/*****************************************************************************/
//	Auteur:				    Guillaume Pelletier
//	Description:		  	Prototype WifiManager
//	Date de creation:		Octobre 2020
//	But:				    Vérifier le fonctionnement du WifiManager
/*****************************************************************************/
#include <Arduino.h>		//Librairie pour le SDK Arduino
#include <WiFiManager.h>	//Librairie permettant d'utiliser WifiManager

//Déclaration du WifiManager ainsi que des données requises.
WiFiManager wm;
const char* ssid = "ReseauPrototype";
const char* password = "Patate123";

//Lance WiFiManager et tente une connexion selon les paramètres passés sur l'écran de connexion. 
void setup()
{
	WiFi.mode(WIFI_STA);
	Serial.begin(9600);
	delay(1000);
	Serial.println("\n");
	if(!wm.autoConnect(ssid, password))
		Serial.println("Erreur de connexion.");
	else
		Serial.println("Connexion etablie!");
}

//Si la PIN est touchée, les informations sont supprimées et un redémarrage est effectué.
void loop()
{
	if(touchRead(T0) < 50)
	{
		Serial.println("Suppression des reglages et redemarrage...");
		wm.resetSettings();
		ESP.restart();
	}
}
