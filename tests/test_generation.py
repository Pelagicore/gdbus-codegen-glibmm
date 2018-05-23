# -*- Mode: Python -*-

# GDBus - GLib D-Bus Library
#
# Copyright (C) 2018 Luxoft
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General
# Public License along with this library; if not, see <http://www.gnu.org/licenses/>.

import os.path
import pytest

from subprocess import Popen, PIPE

class Generator:
    def __init__(self):
        self.path = '../gdbus-codegen-glibmm.py'

    def run(self, xml_file, output_dir):
        basename = os.path.splitext(os.path.basename(xml_file))[0]
        args = [
                self.path,
                '--generate-cpp-code=%s/%s' % (output_dir, basename),
                xml_file,
                ]
        process = Popen(args, stdout=PIPE, stderr=PIPE)
        process.wait()

        return (
                basename + '_proxy.cpp',
                basename + '_proxy.h',
                basename + '_common.cpp',
                basename + '_common.h',
                basename + '_stub.cpp',
                basename + '_stub.h'
                )


@pytest.fixture(scope="function")
def basename():
    return ''

class TestGenerator(object):

    @pytest.mark.parametrize('basename', [
        'simple',
        'many-types',
        ])
    def test_simple(self, basename, tmpdir):
        generator = Generator()
        files = generator.run('data/%s/input.xml' % basename, tmpdir)
        for file_name in files:
            file_path = tmpdir.join(file_name)

            # gdbus-codegen-glibmm writes the full pathname of some
            # generated include file in the #include directives: in
            # order to get a reproducible output, let's replace it with
            # a fixed string, "OUTPUT_DIR":
            contents = file_path.read()
            file_path.write(contents.replace(str(tmpdir), 'OUTPUT_DIR'))

            # run `diff` on the generated file and verify that it
            # matches the expected file.
            expected_file_path = 'data/%s/%s' % (basename, file_name)
            args = ['diff', '-uN', expected_file_path, file_path]
            process = Popen(args, stdout=PIPE)
            (output_data, err) = process.communicate()
            diff = output_data.decode("utf-8") if output_data else ''
            assert diff == ''
