class stack:
    def __init__(self):
        self.__data = []
    def empty(self):
        if len(self.__data) == 0:
            return True
        else:
            return False
    def size(self):
        return len(self.__data)
    def peek(self):
        return self.__data[-1]
    def push(self,ele):
        self.__data.append(ele)
    def pop(self):
        return self.__data.pop()
    def __del__(self):
        import gc
        gc.collect()
        print("the object has been deleted")
