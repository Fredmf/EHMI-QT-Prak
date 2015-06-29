#!/bin/bash

export QT_QPA_EGLFS_PHYSICAL_WIDTH=45
export QT_QPA_EGLFS_PHYSICAL_HEIGHT=34
export QT_QPA_EGLFS_DEPTH=32

./build/carsmilie -platform eglfs
