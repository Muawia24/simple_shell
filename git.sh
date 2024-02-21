#!/bin/bash
echo "Enter a commit"
read commit
git add .
git commit -m "${commit}"
git push