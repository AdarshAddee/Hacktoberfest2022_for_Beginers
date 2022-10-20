const express = require("express");
const path = require("path");
const fs = require("fs");
const { name } = require("pug/lib");
const app = express();
const port = 80;

// express stuff
app.use('/static', express.static('static'))  // For serving static files
app.use(express.urlencoded())
// pug stuff
app.set('view engine', 'pug')   // Set the template engine as pug 
app.set('views', path.join(__dirname, 'views'))  // Set the views directory
 
// endpoint
app.get("/", (req, res)=>{
    const con = "but i will learn with time"
    const par = {'title': 'it is not a very hard time now' , 'content': con}   
     res.status(200).render('index.pug' , par);
})

app.post('/', (req, res)=>{
  let  name = req.body.name 
  let  gendre = req.body.gendre 
  let  age = req.body.age
  let  address = req.body.address 
  let  more = req.body.more

   let op = `the name of the client is ${name} age is ${gendre} lives at ${age} pronounced as ${address} and more about the client is ${more}`
   fs.writeFileSync('out.txt' , op) 
 const par = {'message': "submitted successfully" }
 res.status(200).render('index.pug' , par);
})


// start the server
app.listen(port, ()=>{
    console.log(`The application started successfully on port ${port}`);
});









