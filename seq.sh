#!/bin/sh
yes|head -n $1 | cat -n | awk '{print $1}'
