char data = '0';   //Variable for storing received data

void setup() 
{
    Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
    pinMode(13, OUTPUT);       //Sets digital pin 13 as output pin for Light
    pinMode(12, OUTPUT);      //Sets digital pin 13 as output pin for Fan
}
void loop()
{
    if(Serial.available() > 0)      // Send data only when you receive data:
    {
        data = Serial.read();        //Read the incoming data and store it into variable data

        // For LED
        if(data == '1')                         //Checks whether value of data is equal to 1 
          digitalWrite(13, HIGH);              //If value is 1 then LED turns ON
        else if(data == '0')                  //Checks whether value of data is equal to 0
          digitalWrite(13, LOW);             //If value is 0 then LED turns OFF

        // For Fan
        else if(data == '2')                //Checks whether value of data is equal to 2
          digitalWrite(12, HIGH);          //If value is 2 then Fan turns ON
        else if(data == '3')              //Checks whether value of data is equal to 3
          digitalWrite(12, LOW);         //If value is 3 then Fan turns OFF
          
        
        //For ALL ON or OFF
        else if(data == '4')  //Checks whether value of data is equal to 4
        { 
            //If value is 4 then LED turns ON
            //If value is 4 then Fan turns ON 
            
            digitalWrite(13, HIGH);
            digitalWrite(12, HIGH); 
       
        } 
        else if(data == '5') //Checks whether value of data is equal to 5
        { 
            //If value is 5 then LED turns OFF
            //If value is 5 then Fan turns OFF
            
            digitalWrite(13, LOW);  
            digitalWrite(12, LOW); 
            
        } 
        
    } 
}