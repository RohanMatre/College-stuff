class Os_Not_found(Exception):
    def _init_(self,message):
        self.message=message
        super()._init_(message)
        self.error_code=392

class Os_not_ubuntu(Exception):
    def _init_(self,message):
        self.message=message
        super()._init_(message)
        self.error_code=394


class Os_version_not_found(Exception):
    def _init_(self,message):
        self.message=message
        super()._init_(message)
        self.error_code=396

class Python_version_not_found(Exception):
    def _init_(self,message):
        self.message=message
        super()._init_(message)
        self.error_code=398

class Library_not_found(Exception):
    def _init_(self,message):
        self.message=message
        super()._init_(message)
        self.error_code=400

class OLibrary_version_not_found(Exception):
    def _init_(self,message):
        self.message=message
        super()._init_(message)
        self.error_code=402