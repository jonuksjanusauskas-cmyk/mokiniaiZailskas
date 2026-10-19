
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const int MAX_MOKINIU = 100;
    const int MAX_PAZ = 10;

    string vardai[MAX_MOKINIU];
    int pazymiai[MAX_MOKINIU][MAX_PAZ];
    int kiek_pazymiu[MAX_MOKINIU];

    int mokiniu_sk = 0;
    int pasirinkimas;

    do
    {
        cout << "\n===== MOKINIU PAZYMIU SISTEMA =====" << endl;
        cout << "1. Ivesti mokini ir jo pazymius" << endl;
        cout << "2. Perziureti visu mokiniu pazymius" << endl;
        cout << "3. Perziureti konkretaus mokinio pazymius" << endl;
        cout << "4. Atnaujinti pazymi" << endl;
        cout << "5. Apskaiciuoti mokinio vidurki" << endl;
        cout << "6. Pasalinti mokini" << endl;
        cout << "7. Iseiti" << endl;
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 1)
        {
            if (mokiniu_sk >= MAX_MOKINIU)
            {
                cout << "Mokiniu sarasas pilnas!" << endl;
            }
            else
            {
                cout << "Iveskite mokinio varda: ";
                cin >> ws;
                getline(cin, vardai[mokiniu_sk]);

                cout << "Kiek pazymiu turi mokinys (0-10): ";
                cin >> kiek_pazymiu[mokiniu_sk];

                while (kiek_pazymiu[mokiniu_sk] < 0 ||
                       kiek_pazymiu[mokiniu_sk] > MAX_PAZ)
                {
                    cout << "Neteisingas kiekis. Iveskite skaiciu nuo 0 iki 10: ";
                    cin >> kiek_pazymiu[mokiniu_sk];
                }

                for (int j = 0; j < kiek_pazymiu[mokiniu_sk]; j++)
                {
                    cout << "Iveskite " << j + 1 << "-aji pazymi (1-10): ";
                    cin >> pazymiai[mokiniu_sk][j];

                    while (pazymiai[mokiniu_sk][j] < 1 ||
                           pazymiai[mokiniu_sk][j] > 10)
                    {
                        cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10: ";
                        cin >> pazymiai[mokiniu_sk][j];
                    }
                }

                mokiniu_sk++;
                cout << "Mokinys sekmingai pridetas!" << endl;
            }
        }
        else if (pasirinkimas == 2)
        {
            if (mokiniu_sk == 0)
            {
                cout << "Mokiniu sarasas tuscias." << endl;
            }
            else
            {
                for (int i = 0; i < mokiniu_sk; i++)
                {
                    cout << "\nMokinys Nr. " << i + 1
                         << ": " << vardai[i] << endl;

                    if (kiek_pazymiu[i] == 0)
                    {
                        cout << "Mokinys pazymiu neturi." << endl;
                    }
                    else
                    {
                        cout << "Pazymiai: ";

                        for (int j = 0; j < kiek_pazymiu[i]; j++)
                        {
                            cout << pazymiai[i][j] << " ";
                        }

                        cout << endl;
                    }
                }
            }
        }
        else if (pasirinkimas == 3)
        {
            if (mokiniu_sk == 0)
            {
                cout << "Mokiniu sarasas tuscias." << endl;
            }
            else
            {
                int nr;

                cout << "Iveskite mokinio numeri (1-"
                     << mokiniu_sk << "): ";
                cin >> nr;

                while (nr < 1 || nr > mokiniu_sk)
                {
                    cout << "Neteisingas mokinio numeris. "
                         << "Iveskite skaiciu nuo 1 iki "
                         << mokiniu_sk << ": ";
                    cin >> nr;
                }

                int i = nr - 1;

                cout << "Mokinys: " << vardai[i] << endl;

                if (kiek_pazymiu[i] == 0)
                {
                    cout << "Mokinys pazymiu neturi." << endl;
                }
                else
                {
                    cout << "Pazymiai: ";

                    for (int j = 0; j < kiek_pazymiu[i]; j++)
                    {
                        cout << pazymiai[i][j] << " ";
                    }

                    cout << endl;
                }
            }
        }
        else if (pasirinkimas == 4)
        {
            if (mokiniu_sk == 0)
            {
                cout << "Mokiniu sarasas tuscias." << endl;
            }
            else
            {
                int nr, paz_nr, naujas_paz;

                cout << "Iveskite mokinio numeri (1-"
                     << mokiniu_sk << "): ";
                cin >> nr;

                while (nr < 1 || nr > mokiniu_sk)
                {
                    cout << "Neteisingas mokinio numeris. "
                         << "Iveskite skaiciu nuo 1 iki "
                         << mokiniu_sk << ": ";
                    cin >> nr;
                }

                int i = nr - 1;

                if (kiek_pazymiu[i] == 0)
                {
                    cout << "Mokinys pazymiu neturi." << endl;
                }
                else
                {
                    cout << "Mokinio " << vardai[i]
                         << " pazymiai: ";

                    for (int j = 0; j < kiek_pazymiu[i]; j++)
                    {
                        cout << j + 1 << ". "
                             << pazymiai[i][j] << "  ";
                    }

                    cout << "\nIveskite pazymio numeri (1-"
                         << kiek_pazymiu[i] << "): ";
                    cin >> paz_nr;

                    while (paz_nr < 1 || paz_nr > kiek_pazymiu[i])
                    {
                        cout << "Neteisingas pazymio numeris. "
                             << "Iveskite skaiciu nuo 1 iki "
                             << kiek_pazymiu[i] << ": ";
                        cin >> paz_nr;
                    }

                    cout << "Iveskite nauja pazymi (1-10): ";
                    cin >> naujas_paz;

                    while (naujas_paz < 1 || naujas_paz > 10)
                    {
                        cout << "Neteisingas pazymys. "
                             << "Iveskite skaiciu nuo 1 iki 10: ";
                        cin >> naujas_paz;
                    }

                    pazymiai[i][paz_nr - 1] = naujas_paz;

                    cout << "Pazymys sekmingai atnaujintas!" << endl;
                }
            }
        }
        else if (pasirinkimas == 5)
        {
            if (mokiniu_sk == 0)
            {
                cout << "Mokiniu sarasas tuscias." << endl;
            }
            else
            {
                int nr;
                double suma = 0;

                cout << "Iveskite mokinio numeri (1-"
                     << mokiniu_sk << "): ";
                cin >> nr;

                while (nr < 1 || nr > mokiniu_sk)
                {
                    cout << "Neteisingas mokinio numeris. "
                         << "Iveskite skaiciu nuo 1 iki "
                         << mokiniu_sk << ": ";
                    cin >> nr;
                }

                int i = nr - 1;

                if (kiek_pazymiu[i] == 0)
                {
                    cout << "Mokinys pazymiu neturi." << endl;
                }
                else
                {
                    for (int j = 0; j < kiek_pazymiu[i]; j++)
                    {
                        suma += pazymiai[i][j];
                    }

                    double vidurkis = suma / kiek_pazymiu[i];

                    cout << fixed << setprecision(2);
                    cout << "Mokinio " << vardai[i]
                         << " vidurkis: " << vidurkis << endl;
                }
            }
        }
        else if (pasirinkimas == 6)
        {
            if (mokiniu_sk == 0)
            {
                cout << "Mokiniu sarasas tuscias." << endl;
            }
            else
            {
                int nr;

                cout << "Iveskite mokinio numeri, kuri norite pasalinti (1-"
                     << mokiniu_sk << "): ";
                cin >> nr;

                while (nr < 1 || nr > mokiniu_sk)
                {
                    cout << "Neteisingas mokinio numeris. "
                         << "Iveskite skaiciu nuo 1 iki "
                         << mokiniu_sk << ": ";
                    cin >> nr;
                }

                int i = nr - 1;

                for (int j = i; j < mokiniu_sk - 1; j++)
                {
                    vardai[j] = vardai[j + 1];
                    kiek_pazymiu[j] = kiek_pazymiu[j + 1];

                    for (int k = 0; k < kiek_pazymiu[j + 1]; k++)
                    {
                        pazymiai[j][k] = pazymiai[j + 1][k];
                    }
                }

                mokiniu_sk--;

                cout << "Mokinys pasalintas is saraso." << endl;
            }
        }
        else if (pasirinkimas == 7)
        {
            cout << "Programa baigta." << endl;
        }
        else
        {
            cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
        }

    } while (pasirinkimas != 7);

    return 0;
}
