const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})

//create a todo app that users store todos on the server
//try http server from scratch in C
//create a http sever in rust using actixx-web
//create an http server in golang using gurrilla framework
//spring boot