#!/usr/bin/env python3

from setuptools import setup, find_packages
import codegen_glibmm

setup(
    name = "gdbus-codegen.glibmm",
    version = codegen_glibmm.version,
    packages = find_packages(),
    entry_points = {
        'console_scripts': [
            'gdbus-codegen-glibmm = codegen_glibmm.codegen_main:codegen_main',
        ]
    }
 )
