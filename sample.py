class CustomEx(Exception):
    def __init__(self, string):
        self.string = string
        super().__init__(self.string)
        print("Custom Exception:", self.string)

try:
    # Error 1: Check OS file name
    os_filename = "ubuntu"
    if os_filename != "ubuntu":
        raise CustomEx("Error 1: OS is not found")

    # Error 2: Check OS version
    os_version = "18.02"
    if os_version != "18.02":
        raise CustomEx("Error 2: OS version is not found")

    # Error 3: Check Python version
    python_version = "3.7"
    if python_version != "3.7":
        raise CustomEx("Error 3: Python version is not found")

    # Error 4: Check libraries and versions
    libraries = {
        "numpy": "1.21",
        "pandas": "0.20.3",
        "tensorflow": "1.13.1",
    }
    for library, version in libraries.items():
        try:
            # Check if the library is installed and the version matches
            import importlib
            lib = importlib.import_module(library)
            if lib.__version__ != version:
                raise CustomEx(f"Error 4: {library} version mismatch")
        except ImportError:
            raise CustomEx(f"Error 4: {library} not found")

    # Dockerfile commands
    dockerfile = """
    FROM ubuntu:18.04
    RUN apt-get update && apt-get install -y python3.7
    RUN python3.7 -m pip install numpy==1.21 pandas==0.20.3 tensorflow==1.13.1
    """
    print("Dockerfile:\n", dockerfile)

    # Error 5: Division by 2
    x = int(input("Enter 1st num: "))
    while True:
        value_input = int(input("Enter division value: "))

        if value_input == 2:
            raise CustomEx("Error 5: Division by 2")
        elif value_input == 0:
            raise CustomEx("Error 6: ZeroDivision Error")
            break
        else:
            print("Ans:", x / value_input)

except CustomEx as ce:
    print(ce)
except Exception as e:
    print("An unexpected error occurred:", e)
