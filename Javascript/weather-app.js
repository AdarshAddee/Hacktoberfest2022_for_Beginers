// Github username: ashish-parjapat
// Aim: this app shows the tempearture of of the city enter by user
// Date: 02-10-2022

const { response } = require("express");
const express = require("express");
const { json } = require("express/lib/response");
const https = require("https");
const app = express();
const bodyParser = require("body-parser")
app.use(bodyParser.urlencoded({ extended: true }))

app.get("/", function(req, res) {
    res.sendFile(__dirname + "/index.html");


})
var cityname;
app.post("/", function(requ, resp) {
    cityname = requ.body.city;
    const url = "https://api.openweathermap.org/data/2.5/weather?q=" + cityname + "&appid=15c39eba3d1061ab9a65bd144144b270&units=metric"
    https.get(url, function(response) {
        // console.log(response);
        response.on("data", function(data) {
            resp.setHeader("Content-Type", "text/html");
            var weatherdetails = JSON.parse(data);
            var parti = weatherdetails.main.temp;
            var weatherdesc = weatherdetails.weather[0].description;
            const icon = weatherdetails.weather[0].icon;
            var imageurl = "https: //openweathermap.org/img/wn/" + icon + "@2x.png ";

            resp.write("the weather is currently " + weatherdesc + "\n");
            resp.write("<h1>the temperature  at " + cityname + " is " + parti + " </h1> \n");
            resp.write(" <img src = " + imageurl + " > ");
            resp.send()
        })
    })


})







app.listen(3000, function() {
    console.log("server staretd at port 3000")
})
