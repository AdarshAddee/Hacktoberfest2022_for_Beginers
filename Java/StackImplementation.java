class StackImplementation {
        public static void main(String[] args) {
            MyStack stack = new MyStack(8);
            stack.push(10);
            stack.push(11);
            stack.push(12);
            System.out.println(stack.peek());;
            stack.pop();
            System.out.println(stack.pop());;
            stack.push(5);
            System.out.println(stack.peek());;
        }
    }
    class MyStack {
        private int top=-1;
        private int[] stack;
        private int size;
        public MyStack(int size)
        {
            this.size=size;
            stack=new int[size];
        }
        public void push(int x)
        {
            if(isFull())
            System.out.println("Stack is Full");
            this.stack[++top]=x;
        }
        public boolean isFull()
        {
            return top == size-1;
        }
        public boolean isEmpty()
        {
            return top == -1;
        }
        public int pop()
        {
            if(isEmpty())
            System.out.println("Stack is Empty");
            return stack[top--];
        }
        public int peek()
        {
            if(isEmpty())
            System.out.println("Stack is empty");
            return stack[top];
        }
    }
