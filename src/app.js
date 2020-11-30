'use strict'

const express = require('express')
const bodyParser = require('body-parser')
const mongoose = require('mongoose')

const app = express()
const port = process.env.PORT || 3000

const Sensores = require('./models/sensores')


app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json())

const usersRoutes = require('./routes/users')

mongoose.Promise = global.Promise;
mongoose.connect('mongodb://localhost:27017/paralelo',
	{ useNewUrlParser: true }, (err, res) => {
		if (err) {
			return console.log('Error al conectar con la base de datos ')
		}
		console.log('Conexion a la base de datos establecida')

		app.listen(port, () => {
			console.log('corriendo api rest en http://localhost:3000')
		})
	})

//routes
app.use('/users', usersRoutes);


