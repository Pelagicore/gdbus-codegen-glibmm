#!/usr/bin/env python3

from setuptools import setup, find_packages
import sys, shutil, os
import codegen_glibmm

cmake_config_file = "cmake-files/gdbus-codegen-glibmm-config.cmake"
cmake_version_file = "cmake-files/gdbus-codegen-glibmm-config-version.cmake"

shutil.copyfile(cmake_version_file + ".in", cmake_version_file)
os.system("sed -i 's/%VERSION%/"+codegen_glibmm.version+"/g' " + cmake_version_file)

setup(
    name = "gdbus-codegen.glibmm",
    version = codegen_glibmm.version,
    include_package_data=True,
    packages = find_packages(),
    package_data = {
        "": ["*.templ"]
    },
    entry_points = {
        'console_scripts': [
            'gdbus-codegen-glibmm = codegen_glibmm.codegen_main:codegen_main',
        ]
    },
    data_files = [(sys.prefix + "/lib/cmake/gdbus-codegen-glibmm-" + codegen_glibmm.version,
                   [cmake_version_file, cmake_config_file])]
 )
