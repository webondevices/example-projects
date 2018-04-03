const AWS = require('aws-sdk');
AWS.config.update({region: 'eu-west-2'});

const doc = require('dynamodb-doc');
const dynamo = new doc.DynamoDB();

const date = new Date;
    
// Return all items before current time
const params1 = {
    TableName: "temp-data",
    ProjectionExpression: "#datetime, #temperature, #humidity",
    FilterExpression: "#datetime < :now",
    ExpressionAttributeNames:{
        "#temperature": "temperature",
        "#datetime": "datetime",
        "#humidity": "humidity"
    },
    ExpressionAttributeValues: {
        ":now": date.getTime()
    }
};

// Return entries over 21.5 degrees
const params2 = {
    TableName: "temp-data",
    ProjectionExpression: "#datetime, #temperature, #humidity",
    FilterExpression: "#temperature > :temp",
    ExpressionAttributeNames:{
        "#temperature": "temperature",
        "#datetime": "datetime",
        "#humidity": "humidity"
    },
    ExpressionAttributeValues: {
        ":temp": 21.5
    }
};

// Return entries where humidity is between 52 and 53
const params3 = {
    TableName: "temp-data",
    ProjectionExpression: "#datetime, #temperature, #humidity",
    FilterExpression: "#humidity between :hummin and :hummax",
    ExpressionAttributeNames:{
        "#temperature": "temperature",
        "#datetime": "datetime",
        "#humidity": "humidity"
    },
    ExpressionAttributeValues: {
        ":hummin": 52,
        ":hummax": 53
    }
};
     
dynamo.scan(params1, function (err, data) {
    console.log(err, data);
});