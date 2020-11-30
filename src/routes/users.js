const router = require('express-promise-router')();

const {
    index,
    newUser
} = require('../controllers/user');


router.get('/', index);
router.post('/', newUser);

module.exports = router;