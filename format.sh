#!/bin/bash

clang-format-11 -style=file -i $(find . -name "*.[hc]")
