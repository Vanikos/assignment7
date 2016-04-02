/* Διαβάστε τον κώδικα, προσπαθήστε να καταλάβετε τι κάνει από μόνοι σας (σκοπίμως δεν έχουν μπει σχόλια που να εξηγούν
τι κάνουν οι διάφορες εντολές) και μετά γράψτε μόνοι σας το υπόλοιπο πρόγραμμα με τις οδηγίες που θα βρείτε στα σχόλια.
Χρησιμοποιήστε της μεταβλητές αληθείας (boolean) ώστε οι εντολές της κάθε κατάστασης (state) να εκτελούνται μόνο μια φορά.
Ο σκοπός σας είναι, να τελειώσετε το πρόγραμμα στο σπίτι και όταν το δοκιμάσετε στο αμαξάκι, το αμαξάκι να επιδείξει
την εξής συμπεριφορά:
Θα προχωρήσει περίπου 20 εκατοστά και θα στρίψει 180 μοίρες (αυτό είναι ήδη έτοιμο για εσάς).
Θα προχωρήσει ΕΠΙΠΛΕΟΝ περίπου 60 εκατοστά (δηλαδή πόσα απ' την αρχή της λειτουργίας του;) και θα στρίψει 90 μοίρες προς
τα αριστερά...
Τέλος, θα συνεχίσει να κινείται ευθεία, μέχρι να διανύσει συνολικά (από την αρχή δηλαδή της λειτουργίας του) 150 εκατοστά. */
#include <Smartcar.h>

Odometer encoderLeft(190), encoderRight(190); //Βάλτε τους δικούς σας παλμούς ανά μέτρο
Gyroscope gyro(13); //Βάλτε την κατάλληλη τιμή σύμφωνα με το γυροσκόπιό σας
Car folkracer;
boolean state1Done = false;
boolean state2Done = false;

void setup() {
  gyro.attach();
  encoderLeft.attach(3); //Χρησιμοποιήστε τα σωστά pins!
  encoderRight.attach(2);
  encoderLeft.begin();
  encoderRight.begin();
  gyro.begin();
  folkracer.begin(encoderLeft, encoderRight, gyro);
  folkracer.enableCruiseControl();
  folkracer.setSpeed(0.5);
}

void loop() {
  folkracer.updateMotors();
  unsigned long distance = encoderLeft.getDistance();
  distance = distance + encoderRight.getDistance();
  distance = distance / 2;
  if (distance > 20) { // Εαν η απόσταση ειναι > 20
    if (distance < 30) {  // ή η απόσταση ειναι < 30
      if (state1Done == false) {
        folkracer.stop(); // το αυτοκινητάκι σταματάει
        folkracer.rotate(180); // το αυτοκινητάκι περιστέφεται 180 μοίρες
        folkracer.setSpeed(0.5); // η ταχύτητα του αυτοκινήτου ειναι 0,5
        state1Done = true;
      }
    }
  }
  folkracer.updateMotors();
  if (distance > 160) { // Εαν η απόσταση ειναι > 80
    if (distance < 1800) { // ή η απόσταση ειναι < 90
      if (state1Done == false) {
        folkracer.stop(); // το αυτοκινητάκι σταματάει
        folkracer.rotate(90); // το αυτοκινητάκι περιστέφεται 90 μοίρες
        folkracer.setSpeed(0.5); // η ταχύτητα του αυτοκινήτου ειναι 0,5
        state1Done = true;
      }
    }
  }
  folkracer.updateMotors(); 
  if (distance > 300) { // Εαν η απόσταση ειναι > 150
    if (state1Done == false) {
        folkracer.stop(); // το αυτοκινητάκι σταματάει
        folkracer.setSpeed(0); // η ταχύτητα του αυτοκινήτου ειναι 0
    }
  }      
  //TO-DO
  //Όταν το αυτοκινητάκι έχει διανύσει από 80 μέχρι 90 εκατοστά, τότε σταματήστε το και μετά περιστρέψτε το κατά 90 μοίρες
  //στα δεξιά. Στη συνέχεια, θέστε ταχύτητα 0.5 μέτρα το δευτερόλεπτο
  
  //TO-DO
  //Όταν το αυτοκινητάκι έχει διανύσει απόσταση μεγαλύτερη των 150 εκατοστών, τότε πείτε του να σταματήσει (ή εναλλακτικά θέστε
  //ταχύτητα μηδέν)
}
