/*
Written by Jin Ju Kim
app.js is used to host the backend server using the Node.js
written in javascript, as well as use few npm packages
for logic to carry out the functions in application.
*/

// Using express framework allows Node.js to host a local
// webserver as well as GET and POST HTTP request 
// between client and server
const express = require('express');
const fileUpload = require('express-fileupload');
var bodyParser = require("body-parser");
const app = express();

app.use(fileUpload());
app.use(bodyParser.urlencoded({extended: true}));


// We use the child_process to run the script .sh file
// on the server
const exec = require('child_process').exec;

// fs is used to store a string into a text file
// on the server side
var fs = require('fs');

var results = '';

// sets ejs as the default file to render
app.set("view engine", "ejs");

// let express know where to find public files
app.use(express.static(__dirname + '/public'));

function runScript(subgraphSize, numNetwork, fileName, callback) {
	var yourscript = exec('sh run.sh graph.txt ' + subgraphSize + ' ' + numNetwork,
        (error, stdout, stderr) => {
        	results = 'filename = ' + fileName + stdout.substring(20);
            //console.log(results);
            //console.log(`${stderr}`);
            if (error !== null) {
                console.log(`exec error: ${error}`);
            }

	callback();
	});
}

app.post("/runNetworkMotif", function(req, res){
	var subgraphSize = req.body.subgraphSize;
	var numNetwork = req.body.numNetwork;
	let fileInput = req.files.fileInput;
	var fileName = fileInput.name;
	console.log('Inquiry is made for ' + fileName +
				'\nwith subgraph size: ' + subgraphSize +
				'\nand number of random network: ' + numNetwork +
				'\n.\n.\n.');
	fileInput.mv('graph.txt', function(err) {
		if(err) return res.status(500).send(err);
	});

	runScript(subgraphSize, numNetwork, fileName, function(){
		console.log('nemolib inquiry for ' + fileName + ' ended');
		console.log('Redirecting the user back to index.ejs' +
					'\n.\n.\n.');
		res.redirect("/");
	});
})

// this sends a GET HTTP request to the server to retrieve
// this page. In this case, index.ejs is called to be rendered
// when a root of the server is accessed. "/".
app.get("/", function(req, res){
	res.render('index', {results: results});
})

app.get("*", function(req, res){
	res.render('index', {results: results});
})

// listen starts a localhost server at ping 3000.
app.listen(3000, function(){
	console.log("Starting localhost server at 3000");
})