from exception import *

with open('requirement.txt', 'r') as f:

    lines = [line.strip() for line in f.readlines()]

    info = {k: v for line in lines[:3]
            if ':' in line for k, v in [line.split(':')]}

    if info.get('OS') == None or info['OS'] == '':
        raise Os_Not_found('OS not found')

    if info['OS'].lower() != 'ubuntu':
        raise Os_not_ubuntu('OS is not Ubuntu')

    if info.get('OS_Version') == None or info['OS_Version'] == '':
        raise Os_version_not_found('OS Version not found')

    if info.get('Python') == None or info['OS'] == '':
        raise Python_version_not_found('Python version has not been mentioned')

    if len(info) == len(lines):
        raise Library_not_found('No libraries found in the requirements file')

    libraries = {}
    for line in lines[len(info):]:
        if '==' in line:
            k, v = line.split('==')
            libraries[k] = v
        elif line != '':
            raise OLibrary_version_not_found(f"No version mentioned for {line}")

    if len(libraries) == 0:
        raise Library_not_found('No libraries found in the requirements file')

with open('Dockerfile', 'w') as f:
    f.write(f"FROM {info['OS'].lower()}:{info['OS_Version']}\n\n")
    f.write(f"RUN apt-get install python{info['Python']}\n\n")

    for library in libraries:
        f.write(
            f"RUN python3 -m pip install {library}=={libraries[library]}\n")

    f.write(f'\nRUN echo "Compilation Successful"\n')
