class ExceptionEx(Exception):
    def __init__(self, string):
        self.string = string
        super().__init__(self.string)
        print("Error:", self.string)

try:
    with open("sample.txt", "r") as f:
        for line in f:
            line = line.strip()  # Remove leading/trailing whitespace
            if line == "Hello":
                print(line)
            else:
                raise ExceptionEx("Line does not match 'Hello'")
except ExceptionEx as ee:
    print(ee)
except FileNotFoundError:
    print("Error: File 'sample.txt' not found")
except Exception as e:
    print("An unexpected error occurred:", e)






