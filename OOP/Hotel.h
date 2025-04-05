#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <vector>

// Clasa de bază pentru persoane
class Persoana {
private:
    std::string nume;
    std::string prenume;
    std::string CNP;
    int varsta;

public:
    // Constructori
    Persoana();
    Persoana(const std::string& nume, const std::string& prenume, const std::string& CNP, int varsta);
    Persoana(const Persoana& other);
    
    // Destructor
    virtual ~Persoana();
    
    // Getteri și setteri
    std::string getNume() const;
    void setNume(const std::string& nume);
    std::string getPrenume() const;
    void setPrenume(const std::string& prenume);
    std::string getCNP() const;
    void setCNP(const std::string& CNP);
    int getVarsta() const;
    void setVarsta(int varsta);
    
    // Metode virtuale
    virtual void afisare() const;
    virtual std::string getTip() const;
    
    // Operatori
    Persoana& operator=(const Persoana& other);
    bool operator==(const Persoana& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Persoana& persoana);
    friend std::istream& operator>>(std::istream& is, Persoana& persoana);
};

// Clasa derivată pentru clienți
class Client : public Persoana {
private:
    int numarRezervari;
    bool clientFidel;
    
public:
    // Constructori
    Client();
    Client(const std::string& nume, const std::string& prenume, const std::string& CNP, 
           int varsta, int numarRezervari = 0, bool clientFidel = false);
    Client(const Client& other);
    
    // Destructor
    ~Client() override;
    
    // Getteri și setteri
    int getNumarRezervari() const;
    void setNumarRezervari(int numarRezervari);
    bool isClientFidel() const;
    void setClientFidel(bool clientFidel);
    
    // Metode suprascrise
    void afisare() const override;
    std::string getTip() const override;
    
    // Operatori
    Client& operator=(const Client& other);
    bool operator==(const Client& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Client& client);
    friend std::istream& operator>>(std::istream& is, Client& client);
};

// Clasa derivată pentru angajați
class Angajat : public Persoana {
private:
    std::string functie;
    double salariu;
    int aniExperienta;
    
public:
    // Constructori
    Angajat();
    Angajat(const std::string& nume, const std::string& prenume, const std::string& CNP, 
            int varsta, const std::string& functie, double salariu, int aniExperienta);
    Angajat(const Angajat& other);
    
    // Destructor
    ~Angajat() override;
    
    // Getteri și setteri
    std::string getFunctie() const;
    void setFunctie(const std::string& functie);
    double getSalariu() const;
    void setSalariu(double salariu);
    int getAniExperienta() const;
    void setAniExperienta(int ani);
    
    // Metode suprascrise
    void afisare() const override;
    std::string getTip() const override;
    
    // Operatori
    Angajat& operator=(const Angajat& other);
    bool operator==(const Angajat& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Angajat& angajat);
    friend std::istream& operator>>(std::istream& is, Angajat& angajat);
};

// Clasa pentru tipurile de camere
class TipCamera {
private:
    std::string denumire;
    int numarMaximPersoane;
    bool areBalcon;
    bool areVedere;
    
public:
    // Constructori
    TipCamera();
    TipCamera(const std::string& denumire, int numarMaximPersoane, bool areBalcon, bool areVedere);
    TipCamera(const TipCamera& other);
    
    // Destructor
    ~TipCamera();
    
    // Getteri și setteri
    std::string getDenumire() const;
    void setDenumire(const std::string& denumire);
    int getNumarMaximPersoane() const;
    void setNumarMaximPersoane(int numar);
    bool hasBalcon() const;
    void setAreBalcon(bool areBalcon);
    bool hasVedere() const;
    void setAreVedere(bool areVedere);
    
    // Operatori
    TipCamera& operator=(const TipCamera& other);
    bool operator==(const TipCamera& other) const;
    friend std::ostream& operator<<(std::ostream& os, const TipCamera& tipCamera);
    friend std::istream& operator>>(std::istream& is, TipCamera& tipCamera);
};

// Clasa pentru camere
class Camera {
private:
    int numar;
    double pretPeNoapte;
    bool ocupata;
    TipCamera tip;
    int etaj;
    
public:
    // Constructori
    Camera();
    Camera(int numar, double pretPeNoapte, bool ocupata, const TipCamera& tip, int etaj);
    Camera(const Camera& other);
    
    // Destructor
    ~Camera();
    
    // Getteri și setteri
    int getNumar() const;
    void setNumar(int numar);
    double getPretPeNoapte() const;
    void setPretPeNoapte(double pret);
    bool isOcupata() const;
    void setOcupata(bool ocupata);
    TipCamera getTip() const;
    void setTip(const TipCamera& tip);
    int getEtaj() const;
    void setEtaj(int etaj);
    
    // Metode
    void afisare() const;
    
    // Operatori
    Camera& operator=(const Camera& other);
    bool operator==(const Camera& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Camera& camera);
    friend std::istream& operator>>(std::istream& is, Camera& camera);
};

// Clasa pentru rezervări
class Rezervare {
private:
    static int numarTotalRezervari;
    int id;
    Client client;
    Camera camera;
    std::string dataCheckIn;
    std::string dataCheckOut;
    int numarZile;
    double pretTotal;
    bool platita;
    
public:
    // Constructori
    Rezervare();
    Rezervare(const Client& client, const Camera& camera, const std::string& dataCheckIn, 
              const std::string& dataCheckOut, int numarZile, bool platita = false);
    Rezervare(const Rezervare& other);
    
    // Destructor
    ~Rezervare();
    
    // Getteri și setteri
    int getId() const;
    Client getClient() const;
    void setClient(const Client& client);
    Camera getCamera() const;
    void setCamera(const Camera& camera);
    std::string getDataCheckIn() const;
    void setDataCheckIn(const std::string& data);
    std::string getDataCheckOut() const;
    void setDataCheckOut(const std::string& data);
    int getNumarZile() const;
    void setNumarZile(int zile);
    double getPretTotal() const;
    void setPretTotal(double pret);
    bool isPlatita() const;
    void setPlatita(bool platita);
    
    // Metode
    void calculeazaPretTotal();
    void afisare() const;
    
    // Operatori
    Rezervare& operator=(const Rezervare& other);
    bool operator==(const Rezervare& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rezervare& rezervare);
    friend std::istream& operator>>(std::istream& is, Rezervare& rezervare);
};

// Clasa pentru hotelul în sine
class Hotel {
private:
    std::string nume;
    std::string adresa;
    int numarStele;
    std::vector<Camera> camere;
    std::vector<Client> clienti;
    std::vector<Angajat> angajati;
    std::vector<Rezervare> rezervari;
    
public:
    // Constructori
    Hotel();
    Hotel(const std::string& nume, const std::string& adresa, int numarStele);
    Hotel(const Hotel& other);
    
    // Destructor
    ~Hotel();
    
    // Getteri și setteri
    std::string getNume() const;
    void setNume(const std::string& nume);
    std::string getAdresa() const;
    void setAdresa(const std::string& adresa);
    int getNumarStele() const;
    void setNumarStele(int stele);
    
    // Metode pentru gestionarea camerelor
    void adaugaCamera(const Camera& camera);
    void stergeCamera(int numarCamera);
    Camera* gasesteCamera(int numarCamera);
    void afisareCamere() const;
    void afisareCamereLibere() const;
    void afisareCamereOcupate() const;
    
    // Metode pentru gestionarea clienților
    void adaugaClient(const Client& client);
    void stergeClient(const std::string& CNP);
    Client* gasesteClient(const std::string& CNP);
    void afisareClienti() const;
    
    // Metode pentru gestionarea angajaților
    void adaugaAngajat(const Angajat& angajat);
    void stergeAngajat(const std::string& CNP);
    Angajat* gasesteAngajat(const std::string& CNP);
    void afisareAngajati() const;
    
    // Metode pentru gestionarea rezervărilor
    void creeazaRezervare(const Client& client, int numarCamera, const std::string& dataCheckIn, 
                           const std::string& dataCheckOut, int numarZile);
    void anuleazaRezervare(int idRezervare);
    Rezervare* gasesteRezervare(int idRezervare);
    void afisareRezervari() const;
    void afisareRezervariClient(const std::string& CNP) const;
    
    // Alte metode
    void afisare() const;
    double calculeazaVenitTotal() const;
    
    // Operatori
    Hotel& operator=(const Hotel& other);
    friend std::ostream& operator<<(std::ostream& os, const Hotel& hotel);
    friend std::istream& operator>>(std::istream& is, Hotel& hotel);
};

#endif // HOTEL_H