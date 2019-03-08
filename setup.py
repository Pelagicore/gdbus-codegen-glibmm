#!/usr/bin/env python3

from setuptools import setup, find_packages
import codegen_glibmm

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
            'gdbus-codegen-glibmm3 = codegen_glibmm.codegen_main:codegen_main',
        ]
    }
 )
