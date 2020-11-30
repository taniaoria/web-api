const Sensores = require('../models/sensores');

module.exports = {
    
    index: async (req, res, next) => {
       const sensor = await Sensores.find({});
       //throw new Error('dummy error');
       res.status(200).json(sensor); 
    },

    newUser: async (req, res, next) => {
        console.log('POST')
        console.log(req.body)

        const sensor = new Sensores();
        //sensor.estado = 1

        
        sensor.estado = req.body.estado
    
        
        await sensor.save();
    },
};
