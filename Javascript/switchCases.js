var user = "admin";
switch (user) {
  case "admin":
    console.log("You have full access");

    break;
  case "subadmin":
    console.log("You have partial access");

    break;
  case "moderator":
    console.log("You have access for moderating users");

    break;
  case "user":
    console.log("You have access to read only");

    break;

  default:
    break;
}
