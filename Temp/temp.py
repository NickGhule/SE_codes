#! /usr/bin/env python3

import os
import requests

filespath = "~/data/feedback/"
files = os.listdir(filespath)

for file in files:
    feedback = {}
    with open(filespath+file) as f:
        feedback["title"] = f.readline()
        feedback["name"] = f.readline()
        feedback["date"] = f.readline()
        feedback["feedback"] = f.readlines()
    res = requests.post("https://35.193.13.141/feedback", data = feedback)
    res.raise_for_status()
