var isEven = (element) => {
  if (element % 2 === 0) {
    return true;
  }
  return false;
};

console.log(isEven(2));
// console.log(isEven(5));
// console.log(isEven(8));
var result = [2, 4, 6, 8, 10].every(isEven);
console.log(result);
var resultTwo = [2, 4, 6, 8].every((e) => e % 2 === 0);

console.log(resultTwo);
