const fizzBuzz = (total) => {
  for (let i = 1; i <= total; i++) {
    if (i % 3 == 0 && i % 5 === 0) {
      console.log("fizz buzz");
    } else if (i % 3 === 0) {
      console.log("fizz");
    } else if (i % 5 == 0) {
      console.log("buzz");
    } else {
      console.log(i);
    }
  }
};

fizzBuzz(100);