#!/bin/bash

list_packages[0]="highlight-line"
list_packages[1]="highlight-selected"
list_packages[2]="smart-backspace"


for package in "${list_packages[@]}"
do
  apm install $package
done
