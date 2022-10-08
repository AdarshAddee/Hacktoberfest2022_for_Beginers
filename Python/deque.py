class Deque:
    def __init__(self, src_arr=[], max_size=300000):
        self.length = max(max_size, len(src_arr)) + 1
        self.buf = list(src_arr) + [None] * (self.length - len(src_arr))
        self.head = 0
        self.tail = len(src_arr)

    def __index(self, i):
        l = len(self)
        if not -l <= i < l:
            raise IndexError("index out of range: " + str(i))
        if i < 0:
            i += l
        return (self.head + i) % self.length

    def __extend(self):
        ex = self.length - 1
        self.buf[self.tail + 1 : self.tail + 1] = [None] * ex
        self.length = len(self.buf)
        if self.head > 0:
            self.head += ex

    def is_full(self):
        return len(self) >= self.length - 1

    def is_empty(self):
        return len(self) == 0

    def append(self, x):
        if self.is_full():
            self.__extend()
        self.buf[self.tail] = x
        self.tail += 1
        self.tail %= self.length

    def appendleft(self, x):
        if self.is_full():
            self.__extend()
        self.buf[(self.head - 1) % self.length] = x
        self.head -= 1
        self.head %= self.length

    def pop(self):
        if self.is_empty():
            raise IndexError()
        ret = self.buf[(self.tail - 1) % self.length]
        self.tail -= 1
        self.tail %= self.length
        return ret

    def popleft(self):
        if self.is_empty():
            raise IndexError()
        ret = self.buf[self.head]
        self.head += 1
        self.head %= self.length
        return ret

    def __len__(self):
        return (self.tail - self.head) % self.length

    def __getitem__(self, key):
        return self.buf[self.__index(key)]

    def __setitem__(self, key, value):
        self.buf[self.__index(key)] = value

    def __str__(self):
        return "Deque({0})".format(str(list(self)))


dq = Deque([], max_size=1)
print("False: "+str(dq.is_full()))
print("True: "+str(dq.is_empty()))
dq.append(1)
print("True: "+str(dq.is_full()))
print("False: "+str(dq.is_empty()))
