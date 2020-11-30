'use strict'

const mongoose = require('mongoose')
const Schema = mongoose.Schema

const SensoresSchema = Schema({
	estado: String
	
	
})

module.exports = mongoose.model('Sensores', SensoresSchema)
