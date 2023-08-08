with open("requirement.txt","r") as f:

    lines = []
    for line in f.readlines():
        lines.append(line.strip())
    print(lines)

    os = lines[0].split(":")

    if(os[0] != "OS"):
        raise OSNotFound(Exception)
    else:
        print("OS Found")

    if(os[1] != "Ubuntu"):
        raise OSNotSupported(Exception)
    else:
        print("Ubuntu Found")    

    version = lines[1].split(":")

    if version!="OS_VERSION":
        raise OSVersionNotfound(Exception)
    else:
        print("Version Found")      

    pythonversion = lines[2].split(":")

    if pythonversion!="PYTHON":
        raise Python(Exception)  
    else:
        print("PYTHON Found")      

    if len(lines) == 3:
        raise PythonLibrariesNotFound(Exception)
        
    for line in lines[4:]:
            else:
            print("Python libraries found")

