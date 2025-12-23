import glob, os

project = 'src/main'
	
file = open(project + '.cpp', 'r')
lines = file.readlines()
file.close()

versionCode = 0
baseUrl = ""
checkFile = ""
fileName = ""
version = ""
content = ""

for line in lines:
	if "int currentVersion" in line:
		versionCode = int(''.join(i for i in line if i.isdigit()))
		fileName = "firmware.bin"
		version = "2.3.6"
		content = "sửa lỗi"
	if "String baseUrl" in line:
		baseUrl = line.split('"')[1::2][0]
	if "String checkFile" in line:
		checkFile = line.split('"')[1::2][0]

with open(checkFile, 'w', encoding='utf-8') as updater:
    updater.write(
        "{\n"
        f"\t\"versionCode\" : {versionCode},\n"
        f"\t\"fileName\" : \"{fileName}\",\n"
        f"\t\"version\" : \"{version}\",\n"
        f"\t\"content\" : \"{content}\"\n"
        "}"
    )
