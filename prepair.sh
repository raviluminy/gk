#!/bin/bash

chmod +x ./odt-to-txt
path=`pwd`

echo '[diff "odt"]
	binary = true
	textconv = '$path'/odt-to-txt' >> .git/config

