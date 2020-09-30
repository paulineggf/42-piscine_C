#!/bin/sh

find . -type f -iname "*.sh" -execdir basename {} .sh ';'
