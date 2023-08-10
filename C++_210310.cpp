#include <bits/stdc++.h>
int K = 10000;
using namespace std;
class traveller
{
private:
public:
    string ID;
    string Name;

    void getName()
    {
        cout << "Name :" << this->Name << endl;
    }
    void getID()
    {
        cout << "ID :" << this->ID << endl;
    }
    string verifyID(string ID)
    {
        if (this->ID == ID)
        {
            return "True";
        }
        else
            return "False";
    }
    void get_tickets();

    void updateID(string ID)
    {
        this->ID = ID;
        // also update ID to all teh tickets
    }
};
class Commander : public traveller
{
private:
    static vector<Commander> List;
    string Authority;
    static vector<Commander> CommanderList;

public:
    int Experience;
    string LicenseID;
    string LicenceType;
    // constructor
    Commander(string Name, string ID, int Experience, string LicenceType, string LicenseID)
    {
        this->Experience = Experience;
        this->LicenceType = LicenceType;
        this->LicenseID = LicenseID;
        this->ID = ID;
        this->Name = Name;
        this->List.push_back(*this);
    }
    void PrintDetails()
    {
        getName();
        getID();
        cout << "Experience of " << this->Name << "  is: " << this->Experience << " years" << endl;
        cout << "ID of " << this->LicenceType << "  is: " << this->LicenseID << endl;
        cout << "Authority of " << this->Name << "  is: " << this->Authority << endl;
    }
    friend void GetComm();
};
class Passenger : public traveller
{
private:
    static vector<Passenger> List;

public:
    int Validity;

    // constructor
    Passenger(string Name, string ID, int Validity)
    {
        this->ID = ID;
        this->Name = Name;
        this->Validity = Validity;
        this->List.push_back(*this);
    }
    void PrintDetails()
    {
        getName();
        getID();
        cout << "Validity of passenger left is: " << this->Validity << " years" << endl;
    }
    friend void GetPass();
};
class Astronaut : public traveller
{
private:
    int Experience;
    static vector<Astronaut> List;

public:
    string LicenseID;
    string LicenceType;
    // flying or space travel licence

    // constructor
    Astronaut(string Name, string ID, int Experience, string LicenceType, string LicenseID)
    {
        this->Experience = Experience;
        this->LicenceType = LicenceType;
        this->LicenseID = LicenseID;
        this->ID = ID;
        this->Name = Name;
        this->List.push_back(*this);
    }
    void PrintDetails()
    {
        getName();
        getID();
        cout << "Experience of " << this->Name << "  is: " << this->Experience << " years" << endl;
        cout << "ID of " << this->LicenceType << "  is: " << this->LicenseID << endl;
    }
    // set/construct functions here
    // Astronaut,and Commander -infinite validity
    // The Astronaut should have Years of Experience and License ID (type: int / string,unique),, flying license/ Space travel license.
    friend void GetAstro();
};
vector<Astronaut> Astronaut::List;
vector<Passenger> Passenger::List;
vector<Commander> Commander::List;
void GetPass()
{
    int i = (Passenger::List).size();
    int NoOfPass;
    cout << "there are following passengers: " << endl;
    while (i--)
    {
        cout << "-----------------------------------" << endl;
        Passenger::List[i].getName();
        Passenger::List[i].getID();
        cout << "-----------------------------------" << endl
             << endl;
    }
}
void GetAstro()
{
    int i = (Astronaut::List).size();
    int NoOfPass;
    cout << "there are following Astronauts: " << endl;
    while (i--)
    {
        cout << "-----------------------------------" << endl;
        Astronaut::List[i].getName();
        Astronaut::List[i].getID();
        cout << "-----------------------------------" << endl
             << endl;
    }
}
void GetComm()
{
    int i = (Commander::List).size();
    int NoOfPass;
    cout << "there are following Commanders: " << endl;
    while (i--)
    {
        cout << "-----------------------------------" << endl;
        Commander::List[i].getName();
        Commander::List[i].getID();
        cout << "-----------------------------------" << endl
             << endl;
    }
}
class Plannet
{
private:
    static vector<Plannet> List;

public:
    string Name;
    float x, y, z;
    // Constructor
    Plannet(string Name, float x, float y, float z)
    {
        this->Name = Name;
        this->x = x;
        this->y = y;
        this->z = z;
        this->List.push_back(*this);
    }
    Plannet(){};
    void getCoordinates()
    {
        cout << "Name of plannet is: " << this->Name << endl;
        cout << "Coordinates (x,y,z) of plannet are (" << x << "," << y << "," << z << ")"
             << " AU" << endl;
    }
    void GetPlannet();
};
vector<Plannet> Plannet::List;
class Ticket
{
private:
    string role;
    static vector<Ticket> AllTickets;

public:
    float price;
    int IdentityNo;
    string TravellerID;
    string Name;
    Plannet Source;
    Plannet Destiny;
    string Date;
    int validity;
    int JoinedSTC;
    int TicketValid;
    Ticket(Passenger p, Plannet Source, Plannet Destiny, string Date)
    {

        this->TravellerID = p.ID;
        this->Name = p.Name;
        this->role = "Passenger";
        this->Date = Date;
        this->Source = Source;
        this->Destiny = Destiny;
        this->validity = 10;
        this->JoinedSTC = 0;
        this->TicketValid = 1;
        this->IdentityNo = K + AllTickets.size();
        if (p.Validity <= 0)
        {
            cout << "Passenger Validity Expired" << endl;
            (*this).removeticket();
        }
        else
        {
            UpdateSTC();
            cout << "Successfully Booked, your Details are: " << endl;
            (*this).PrintTicket();
        }
    }
    Ticket(Astronaut a, Plannet Source, Plannet Destiny, string Date)
    {
        this->TravellerID = a.ID;
        this->Name = a.Name;
        this->role = "Astronaut";
        this->Date = Date;
        this->Source = Source;
        this->Destiny = Destiny;
        this->validity = 10;
        this->JoinedSTC = 0;
        this->TicketValid = 1;
        this->IdentityNo = K + AllTickets.size();
        UpdateSTC();
        cout << "Successfully Booked, your Details are: " << endl;
        (*this).PrintTicket();
    }
    Ticket(Commander c, Plannet Source, Plannet Destiny, string Date)
    {
        this->TravellerID = c.ID;
        this->Name = c.Name;
        this->role = "Commander";
        this->Date = Date;
        this->Source = Source;
        this->Destiny = Destiny;
        this->validity = 10;
        this->JoinedSTC = 0;
        this->TicketValid = 1;
        this->IdentityNo = K + AllTickets.size();
        UpdateSTC();
        cout << "Successfully Booked, your Details are: " << endl;
        (*this).PrintTicket();
    }
    void BookReturnTicket(string ReturnDate)
    {

        if (this->TicketValid == 1)
        {
            Ticket ReturnTicket = *this;
            ReturnTicket.Date = (ReturnDate);
            ReturnTicket.Source = (this->Destiny);
            ReturnTicket.Destiny = (this->Source);
            UpdateSTC();
            cout << "Successfully Booked return ticket, your Details are: " << endl;
            (*this).PrintTicket();
        }
        else
            cout << "Invalid Ticket";
    }
    void UpdateDate(string Date)
    {
        if (this->TicketValid == 1)
        {
            Ticket New = *this;
            New.Date = Date;
            New.JoinedSTC = 0;
            removeticket();
            New.UpdateSTC();
        }
        else
            cout << "Invalid Ticket";
    }
    void UpdateSource(Plannet p)
    {
        if (this->TicketValid == 1)
        {
            Ticket New = *this;
            New.Source = p;
            New.JoinedSTC = 0;
            removeticket();
            New.UpdateSTC();
        }
        else
            cout << "Invalid Ticket";
    }
    void UpdateDestiny(Plannet p)
    {
        if (this->TicketValid == 1)
        {
            Ticket New = *this;
            New.Destiny = p;
            New.JoinedSTC = 0;
            removeticket();
            New.UpdateSTC();
            cout << "Updated Ticket is: " << endl;
            New.PrintTicket();
        }
        else
            cout << "Invalid Ticket";
    }
    void getName()
    {
        if (this->TicketValid == 1)
        {
            cout << "Name of traveller is " << this->Name;
        }
        else
            cout << "Invalid Ticket";
    }
    void getID()
    {
        if (this->TicketValid == 1)
        {
            cout << "ID of traveller is " << this->TravellerID;
        }
        else
            cout << "Invalid Ticket";
    }
    string sourceName()
    {
        return this->Source.Name;
    }
    string destinyName()
    {
        return this->Destiny.Name;
    }
    void Delete()
    {
        removeticket();
        cout << "Successfully deleted" << endl;
    }
    void PrintTicket()
    {
        cout << "--------------------------------------" << endl;
        cout << "Name of traveller is " << this->Name << endl;
        cout << "Identity number of travel is " << this->IdentityNo << endl;
        cout << "ID of traveller is " << this->TravellerID << endl;
        cout << "Source of travel is " << this->sourceName() << endl;
        cout << "Destiny of travel is " << this->destinyName() << endl;
        cout << "Date of travel is " << this->Date << endl;
        cout << "Validity of ticket is " << this->validity << "years" << endl;
        if (this->JoinedSTC == 0)
            cout << "Space Travel Car is not assigned" << endl;
        else
            cout << "Assigned Space Travel Car number is:  " << JoinedSTC << endl;
        cout << "--------------------------------------" << endl
             << endl;
    }
    void removeticket();
    friend void traveller::get_tickets();
    void UpdateSTC();
};
std::vector<Ticket> Ticket::AllTickets;
void traveller::get_tickets()
{
    int i = (Ticket::AllTickets).size();
    int NoOfTickets = 0;
    cout << "This user have following tickets booked :" << endl;
    while (i--)
    {
        if (Ticket::AllTickets[i].TravellerID == this->ID && Ticket::AllTickets[i].TicketValid == 1)
        {
            (Ticket::AllTickets[i]).PrintTicket();
            NoOfTickets++;
        }
    }
    if (!NoOfTickets)
    {
        cout << "Sorry! No tickets found." << endl;
    }
}
void Ticket::removeticket()
{
    int i = (Ticket::AllTickets).size();
    Ticket::AllTickets[this->IdentityNo - K].TicketValid = 0;
}
class STC
{
private:
    int AstronautID;
    int CommanderID;
    vector<int> ListTickets;
    static vector<STC> List;

public:
    int STCID;
    Plannet Destiny;
    Plannet Source;
    string Date;
    int PassCount;
    STC(int TicketID1, int TicketID2, Plannet Source, Plannet Destiny, string Date)
    {
        this->ListTickets.push_back(TicketID1);
        this->ListTickets.push_back(TicketID2);
        this->Source = Source;
        this->Destiny = Destiny;
        this->Date = Date;
        this->STCID = List.size() + K;
        this->PassCount = 2;
        this->AstronautID = -1;
        this->AstronautID = -1;
        (*this).checkAstCom();
        this->List.push_back(*this);
    }
    string sourceName()
    {
        return this->Source.Name;
    }
    string destinyName()
    {
        return this->Destiny.Name;
    }
    friend void Ticket::UpdateSTC();
    void checkAstCom()
    {
    }
    // check free astraaauu and commmmmmanders

    // STC constructor
    // call destructor when its object get out of scope
    // void addTraveller();
    // – List all travellers
    // – Set the Astronaut ID
    // – Set the Commander ID
    // – Update the astronaut ID, while changing the astronaut.
    // – Change the commander ID, while changing the commander.
};
vector<STC> STC::List;
void Ticket::UpdateSTC()
{
    if (this->role == "Passenger")
    {
        int i = STC::List.size();
        while (i--)
        {
            if (STC::List[i].PassCount < 8)
            {
                if (((STC::List[i]).destinyName()) == this->destinyName() && ((STC::List[i]).sourceName()) == this->sourceName() && ((STC::List[i]).Date) == this->Date)
                {
                    STC::List[i].PassCount++;
                    STC::List[i].ListTickets.push_back(this->IdentityNo);
                    this->JoinedSTC = STC::List[i].STCID;
                    break;
                }
            }
        }
        if (this->JoinedSTC == 0)
        {
            int i = (this->AllTickets).size();
            while (i--)
            {
                if (this->AllTickets[i].JoinedSTC == 0 && this->AllTickets[i].TicketValid == 1)
                {
                    if ((this->AllTickets[i].destinyName()) == this->destinyName() && (this->AllTickets[i].sourceName()) == this->sourceName() && (this->AllTickets[i].Date) == this->Date)
                    {
                        int STCID = STC(this->AllTickets[i].IdentityNo, this->IdentityNo, this->Source, this->Destiny, this->Date).STCID;
                        this->AllTickets[i].JoinedSTC = STCID;
                        this->JoinedSTC = STCID;
                        cout << "aaya hai";
                        break;
                    }
                }
            }
        }
    }
    else if (this->role == "Astronaut")
    {
    }
    else if (this->role == "Commander")
    {
    }
    (Ticket::AllTickets).push_back(*this);
}
int main()
{
    cout << "Welcome to the world of space travel :)" << endl;
    Plannet P1(string("Earth"), 3.2, 3.4, 5.3);
    Plannet P2(string("Mars"), 3.35, 5.4, 23.3);
    Plannet P3(string("Saturn"), 6.2, 5.4, 3.3);
    Passenger Pass1(string("Passenger1"), string("324234"), 9);
    Passenger Pass2(string("Passenger2"), string("324235"), 9);
    Passenger Pass3(string("Passenger3"), string("324236"), 9);
    Passenger Pass4(string("Passenger4"), string("324234"), 9);
    Passenger Pass5(string("Passenger5"), string("324234"), -1);
    Passenger Pass6(string("Passenger6"), string("3242349"), 9);
    Passenger Pass7(string("Passenger7"), string("3242340"), 9);
    Passenger Pass8(string("Passenger8"), string("3242341"), 9);
    Passenger Pass9(string("Passenger9"), string("3242342"), 9);
    Passenger Pass10(string("Passenger10"), string("3242343"), 9);
    Passenger Pass11(string("Passenger11"), string("3242344"), 9);
    Astronaut Astro12(string("Astronaut12"), string("3242345"), 10, string("flyinglicense"), string("423234"));
    Astronaut Astro13(string("Astronaut13"), string("3242346"), 10, string("flyinglicense"), string("423235"));
    Commander Comm14(string("Commander14"), string("3242347"), 11, string("flyinglicense"), string("423236"));
    Commander Comm15(string("Commander15"), string("3242348"), 11, string("flyinglicense"), string("423237"));

    Ticket(Pass1, P1, P2, string("23/12/2032"));
    Ticket(Pass2, P1, P2, string("23/12/2032"));
    Ticket(Pass3, P2, P3, string("23/12/2032"));
    Ticket(Pass4, P2, P3, string("23/12/2032"));
    Ticket(Pass5, P1, P2, string("23/12/2032"));

    ////////////////////////////////////////////////////////
    // cout << "Welcome to the world of space travel :)" << endl;
    // Plannet P1(string("Earth"), 3.2, 3.4, 5.3);
    // Plannet P2(string("Mars"), 3.35, 5.4, 23.3);
    // Plannet P3(string("Saturn"), 6.2, 5.4, 3.3);
    // Passenger Pass1(string("Passenger1"), string("324234"), 9);
    // Passenger Pass2(string("Passenger2"), string("324235"), 9);
    // Passenger Pass3(string("Passenger3"), string("324236"), 9);
    // Passenger Pass4(string("Passenger4"), string("324234"), 9);
    // Passenger Pass5(string("Passenger5"), string("324234"), 9);
    // Passenger Pass6(string("Passenger6"), string("3242349"), 9);
    // Passenger Pass7(string("Passenger7"), string("3242340"), 9);
    // Passenger Pass8(string("Passenger8"), string("3242341"), 9);
    // Passenger Pass9(string("Passenger9"), string("3242342"), 9);
    // Passenger Pass10(string("Passenger10"), string("3242343"), 9);
    // Passenger Pass11(string("Passenger11"), string("3242344"), 9);
    // Astronaut Astro12(string("Astronaut12"), string("3242345"), 10, string("flyinglicense"), string("423234"));
    // Astronaut Astro13(string("Astronaut13"), string("3242346"), 10, string("flyinglicense"), string("423235"));
    // Commander Comm14(string("Commander14"), string("3242347"), 11, string("flyinglicense"), string("423236"));
    // Commander Comm15(string("Commander15"), string("3242348"), 11, string("flyinglicense"), string("423237"));

    // string Command;
    // // defining commands of CLI
    // cout << "Login as:" << endl;
    // cout << "1. Admin" << endl;
    // cout << "2. Passenger" << endl;
    // cout << "3. Astronaut" << endl;
    // cout << "4. Commander" << endl;

    // cin >> Command;
    // while (!(Command == string("exit") || Command == string("Exit")))
    // {
    // }

    // cout << "All the functions and classes are implemented except STC and Price of ticket" << endl
    //      << endl
    //      << "-----------------------------------------------";
}