//print the n numbers [1,2,3,...,n]

function printNnumber(n) {
    if(n===0)return
    printNnumber(n-1)
    console.log(n);
}
//output
//1 2 3 ..... n

printNnumber(10)