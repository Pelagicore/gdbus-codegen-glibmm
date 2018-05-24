#!/usr/bin/env python3

from setuptools import setup, find_packages
setup(
    name = "gdbus-codegen.glibmm",
    version = "0.1",
    packages = find_packages(),
    entry_points = {
        'console_scripts': [
            'gdbus-codegen-glibmm = codegen_glibmm.codegen_main:codegen_main',
        ]
    }
 )
