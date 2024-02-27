// Define los pines para controlar los relés de los motores de la ventana y el pin del pulsador
const int pinRelayAbrir = 11; // Pin para el relé del motor de abrir
const int pinRelayCerrar = 12; // Pin para el relé del motor de cerrar
const int pinPulsador = 10; // Pin para el pulsador

// Define las constantes para los estados de los relés
const int RELAY_ENCENDIDO = LOW; // Los relés se activan con LOW

void setup() {
  // Inicializa los pines
  pinMode(pinRelayAbrir, OUTPUT);
  pinMode(pinRelayCerrar, OUTPUT);
  pinMode(pinPulsador, INPUT_PULLUP); // El pulsador está conectado a tierra cuando se presiona
}

void loop() {
  // Verifica si el pulsador está presionado
  if (digitalRead(pinPulsador) == 1) {
    abrirOcerrarVentana(); // Llama a la función para abrir o cerrar la ventana
    delay(7000); // Espera un tiempo para evitar rebotes del pulsador
  }
}

// Función para abrir o cerrar la ventana
void abrirOcerrarVentana() {
  // Determina si la ventana está abierta o cerrada
  if (digitalRead(pinRelayAbrir) == RELAY_ENCENDIDO) {
    // Si la ventana está abierta, ciérrala
    digitalWrite(pinRelayAbrir, !RELAY_ENCENDIDO); // Apaga el relé de abrir
    digitalWrite(pinRelayCerrar, RELAY_ENCENDIDO); // Enciende el relé de cerrar
  } else {
    // Si la ventana está cerrada, ábrela
    digitalWrite(pinRelayAbrir, RELAY_ENCENDIDO); // Enciende el relé de abrir
    digitalWrite(pinRelayCerrar, !RELAY_ENCENDIDO); // Apaga el relé de cerrar
