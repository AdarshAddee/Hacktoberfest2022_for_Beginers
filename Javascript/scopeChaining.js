var name = "harsh";

console.log(name);

function sayName() {
  var name = "Mr. H";
  console.log(name);
  sayName;
  function sayNameAgain() {
    var name = "Mr. H . M";

    console.log(name);
  }
  sayNameAgain();
}
sayName();
