
```cpp
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}


int isPrim(int n){
  int cnt=0;
  if (n <= 1)
        return 0;
    else {

        // Check how many numbers divide n in
        // range 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                cnt++;
        }

        // if cnt is greater than 0 then n is
        // not prime
        if (cnt > 0)
            return 0;

        // else n is prime
        else
            return 1;

    }

    return 0;
}

// the loop function runs over and over again forever
void loop() {
  int i;
  for(i=2;i<155;i++){
    if(isPrim(i)){
      Serial.print(i);
      Serial.print(" ");
      digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(1000);                      // wait for a second
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW:
    }
  

  }

}
```
