# -*- Mode: Python -*-

# GDBus - GLib D-Bus Library
#
# Copyright (C) 2018-2019 Luxoft
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
import sys

from subprocess import Popen, PIPE

class Generator:
    def __init__(self):
        self.path = '../gdbus-codegen-glibmm.py'

    def run(self, xml_file, output_dir, extra_args = []):
        basename = os.path.splitext(os.path.basename(xml_file))[0]
        args = [
                self.path,
                *extra_args,
                '--generate-cpp-code=%s/%s' % (output_dir, basename),
                xml_file,
                ]
        process = Popen(args, stdout=sys.stdout, stderr=sys.stdout)
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


class GeneratedFile:
    def __init__(self, tmpdir, file_name):
        self.file_path = tmpdir.join(file_name)
        # gdbus-codegen-glibmm writes the full pathname of some
        # generated include file in the #include directives: in
        # order to get a reproducible output, let's replace it with
        # a fixed string, "OUTPUT_DIR":
        contents = self.file_path.read()
        self.file_path.write(contents.replace(str(tmpdir), 'OUTPUT_DIR'))

    def diff_with(self, expected_file_path):
        args = ['diff', '-uN', expected_file_path, self.file_path]
        process = Popen(args, stdout=PIPE)
        (output_data, err) = process.communicate()
        return output_data.decode("utf-8") if output_data else ''


class TestGenerator(object):

    @pytest.mark.parametrize('basename', [
        'simple',
        'many-types',
        ])
    def test_simple(self, basename, tmpdir):
        generator = Generator()
        files = generator.run('data/%s/input.xml' % basename, tmpdir)
        for file_name in files:
            generated = GeneratedFile(tmpdir, file_name)

            # run `diff` on the generated file and verify that it
            # matches the expected file.
            expected_file_path = 'data/%s/%s' % (basename, file_name)
            assert generated.diff_with(expected_file_path) == ''


    @pytest.mark.parametrize('error_namespace, expected_files', [
        pytest.param('', 'simple', id='No namespace'),
        pytest.param('com::example::Namespace', 'error_namespace',
            id='With error namespace'),
        ])
    def test_error_namespaces(self, error_namespace, expected_files, tmpdir):
        generator = Generator()
        if error_namespace:
            namespace_param = [ '--errors-namespace=' + error_namespace ]
        else:
            namespace_param = []
        files = generator.run('data/simple/input.xml', tmpdir, namespace_param)
        for file_name in [ f for f in files if '_common.' in f ]:
            generated = GeneratedFile(tmpdir, file_name)

            # run `diff` on the generated file and verify that it
            # matches the expected file.
            expected_file_path = 'data/%s/%s' % (expected_files, file_name)
            assert generated.diff_with(expected_file_path) == ''
