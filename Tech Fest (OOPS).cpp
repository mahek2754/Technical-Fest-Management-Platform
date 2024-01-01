#include <bits/stdc++.h>
using namespace std;

// Forward declarations
class Person; 
class Participant;
class Coordinator;
class CoreMember;
class Workforce;
class Event;

// Global vectors to store instances of different user types
vector<Participant> participants;
vector<CoreMember> core_members;
vector<Coordinator> coordinators;
vector<Workforce> workforce;
vector<Event> Events;

// Base class representing a person
class Person
{
protected:
    string name;
    int id;
    string contactInformation;

public:
    // Getter methods for person attributes
    string getName() const { return name; }
    string getContactInformation() const { return contactInformation; }
    int getId() const { return id; }
};

// Derived class representing a participant
class Participant : public Person
{
private:
    set<int> registeredEvents;

public:
    // Constructor to initialize participant attributes
    Participant(int id, const string &name, const string &contactInformation)
    {
        this->id = id;
        this->name = name;
        this->contactInformation = contactInformation;
    }

    // Getter methods for participant attributes
    int getParticipantID() const { return id; }
    const string &getName() const { return name; }
    const string &getContactInformation() const { return contactInformation; }

    // Method to register for an event
    void registerEvent(int eventID)
    {
        cout << "Participant " << name << " registered for event ID: " << eventID << endl;
        registeredEvents.insert(eventID);
    }

    // Method to unregister from an event
    void unregisterEvent(int eventID)
    {
        cout << "Participant " << name << " unregistered from event ID: " << eventID << endl;
        registeredEvents.erase(eventID);
    }

    // Method to get registered events
    void getRegisteredEvents()
    {
        for (auto it : registeredEvents)
        {
            cout << it << " ";
        }
    }
};

// Forward declaration of Event class
class Event;

// Derived class representing a core member
class CoreMember : public Person
{
private:
    string specialization;
    vector<string> coremembers;
    std::vector<Coordinator *> coordinators;
    std::vector<std::pair<Event *, int>> managingEvents;

public:
    // Constructor to initialize core member attributes
    CoreMember(const string &name, const string &specialization, const string &contactInformation, int id)
    {
        this->id = id;
        this->name = name;
        this->specialization = specialization;
        this->contactInformation = contactInformation;
        coremembers.push_back(name);
    }

    // Display core member details
    void displayDetails() const
    {
        cout << "Core Member Name: " << name << "\nSpecialization: " << specialization << endl;
    }

    // Display all core members
    void displayAllCoremembers() const
    {
        cout << "All core members are : " << endl;
        for (int i = 0; i < coremembers.size(); i++)
        {
            cout << coremembers[i] << " ";
        }
        cout << endl;
    }

    // Getter method for portfolio
    string getPortfolio() const
    {
        return specialization;
    }

    // Add coordinator to the core member
    void addCoordinator(Coordinator *coordinator)
    {
        coordinators.push_back(coordinator);
    }

    // Add event managed by the core member
    void addEvent(Event *event)
    {
        managingEvents.push_back({event, 0});
    }

    // Get coordinators associated with the core member
    vector<Coordinator *> getCoordinators() const
    {
        return coordinators;
    }
};

// Forward declaration of Workforce class
class Workforce;

// Derived class representing a coordinator
class Coordinator : public Person
{
private:
    vector<CoreMember *> coreHeads;
    vector<Workforce *> workforce;
    vector<Event *> eventsManaging;
    vector<string> coordinators;

public:
    // Constructor to initialize coordinator attributes
    Coordinator(const string &name, const string &contactInformation, int id)
    {
        this->id = id;
        this->name = name;
        this->contactInformation = contactInformation;
        coordinators.push_back(name);
    }

    // Add core head to the coordinator
    void addCoreHead(CoreMember *core_head)
    {
        this->coreHeads.push_back(core_head);
    }

    // Add workforce to the coordinator
    void addWorkforce(Workforce *workforce)
    {
        this->workforce.push_back(workforce);
    }

    // Get core heads associated with the coordinator
    vector<CoreMember *> getCoreHeads() const
    {
        return coreHeads;
    }

    // Get workforce associated with the coordinator
    vector<Workforce *> getWorkforce() const
    {
        return workforce;
    }

    // Display all coordinators
    void displayAllCoordinator()
    {
        for (int i = 0; i < coordinators.size(); i++)
        {
            cout << "Coordinators : ";
            cout << coordinators[i] << " ";
        }
        cout << endl;
    }
};

// Definition of Workforce class derived from Person class
class Workforce : public Person
{
private:
    vector<string> workforce; // Vector to store workforce member names

public:
    // Constructor to initialize Workforce attributes
    Workforce(const string &name, const string &contactInformation, int id)
    {
        this->id = id;
        this->name = name;
        this->contactInformation = contactInformation;
        workforce.push_back(name); // Add the workforce member to the vector
    }

    // Getter method to retrieve contact information of the workforce
    string getContactInformation()
    {
        return contactInformation;
    }

    // Display details of the workforce
    void displayDetails() const
    {
        cout << "Workforce Members: ";
        for (int i = 0; i < workforce.size(); i++)
        {
            cout << workforce[i] << " ";
        }
        cout << endl;
    }
};

// Definition of Event class
class Event
{
private:
    vector<string> Events; // Vector to store event names
    vector<int> Event_id;   // Vector to store event IDs
    string Event_name;      // Event name
    int Event_fee;          // Event fee

public:
    // Constructor to initialize Event attributes
    Event(string &Event_name, int Event_id_element, int Event_fee)
    {
        Event_id.push_back(Event_id_element);
        this->Event_name = Event_name;
        this->Event_fee = Event_fee;
        Events.push_back(Event_name); // Add the event to the vector
    }

    // Getter methods to retrieve Event attributes
    const string &getName() const { return Event_name; }
    const int &getFee() const { return Event_fee; }

    // Display details of a specific event
    void get_details_of_events(const Event &e)
    {
        cout << "Event name is: " << e.Event_name << endl;
        auto it = find(Events.begin(), Events.end(), e.Event_name);

        if (it != Events.end())
        {
            size_t index = distance(Events.begin(), it);
            cout << "Event ID is: " << Event_id[index] << endl;
        }
        cout << "Event Fee: " << e.Event_fee << endl;
    }
};


// Function to display details of all events
void get_all_events()
{
    for (size_t i = 0; i < Events.size(); i++)
    {
        cout << "Event ID:  " << i << ", Event Name:  " << Events[i].getName() << ", Event fee:  " << Events[i].getFee() << endl;
    }
}

int nextEventId = 0; // Counter for generating unique event IDs

// Function to get the next available event ID
int getNextEventId()
{
    return nextEventId++;
}

int nextUserId = 0; // Counter for generating unique user IDs

// Function to get the next available user ID
int getNextUserId()
{
    return nextUserId++;
}

// Function to retrieve a Person object based on user ID
Person *getUserFromUserID(int user_id)
{
    // Search for the user in different vectors based on user type
    for (auto &participant : participants)
    {
        if (participant.getId() == user_id)
        {
            return &participant;
        }
    }

    for (auto &core_member : core_members)
    {
        if (core_member.getId() == user_id)
        {
            return &core_member;
        }
    }

    for (auto &coordinator : coordinators)
    {
        if (coordinator.getId() == user_id)
        {
            return &coordinator;
        }
    }

    for (auto &workforce_member : workforce)
    {
        if (workforce_member.getId() == user_id)
        {
            return &workforce_member;
        }
    }

    return nullptr; // Return nullptr if the user is not found
}

// Function to display details of a user
void displayUserDetails(Person *user)
{
    cout << "User Details:" << endl;
    if (!user)
    {
        cout << "No user with provided user id found." << endl;
        return;
    }
    cout << "Name: " << user->getName() << endl;
    cout << "User ID: " << user->getId() << endl;
    cout << "Contact Information: " << user->getContactInformation() << endl;
}

// Function to display details of all core members
void displayAllCoreMemberDetails()
{
    cout << "All Core Member Details:" << endl;
    for (const auto &core_member : core_members)
    {
        cout << "\tName: " << core_member.getName() << ", ";
        cout << "\tUser ID: " << core_member.getId() << ", ";
        cout << "\tContact Information: " << core_member.getContactInformation() << ", ";
        cout << "\tPortfolio: " << core_member.getPortfolio() << endl;
    }
}


int main()
{
    while (true)
    {
        cout << "Choose an option:" << endl;
        cout << "0. Create Event" << endl;
        cout << "1. Create Participant" << endl;
        cout << "2. Create Core Member" << endl;
        cout << "3. Create Coordinator" << endl;
        cout << "4. Create Workforce" << endl;
        cout << "5. Register Participant for Event" << endl;
        cout << "6. Add Coordinator to Core Member" << endl;
        cout << "7. Add Workforce to Coordinator" << endl;
        cout << "8. Display User Details" << endl;
        cout << "9. Display All Core Member Details" << endl;
        cout << "10. Exit" << endl;

        int option;
        cin >> option;

        if (option == 0)
        {
            int fee;
            string e_name;
            int event_id = getNextEventId();
            cout << "Enter Event details:" << endl;
            cout << "Name: ";
            cin >> e_name;
            cout << "Event Fee: ";
            cin >> fee;
            Events.push_back(Event(e_name, event_id, fee));
            cout << "Your Event Id: " << event_id << endl;
            Event(e_name, event_id, fee).get_details_of_events(Event(e_name, event_id, fee));
        }

        else if (option == 1)
        {
            string name, contact_info;
            int user_id = getNextUserId();
            cout << "Enter Participant details:" << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Contact Information: ";
            cin >> contact_info;
            participants.push_back(Participant(user_id, name, contact_info));
            cout << "Your User Id: " << user_id << endl;
        }
        else if (option == 2)
        {
            string name, contact_info, Specialisation;
            int user_id = getNextUserId();
            cout << "Enter Core Member details: " << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Contact Information: ";
            cin >> contact_info;
            cout << "Specialisation: ";
            cin >> Specialisation;
            core_members.push_back(CoreMember(name, Specialisation, contact_info, user_id));
            cout << "Your User Id: " << user_id << endl;
        }
        else if (option == 3)
        {
            string name, contact_info;
            int user_id = getNextUserId();
            cout << "Enter Coordinator details: " << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Contact Information: ";
            cin >> contact_info;
            coordinators.push_back(Coordinator(name, contact_info, user_id));
            cout << "Your User Id: " << user_id << endl;
        }
        else if (option == 4)
        {
            string name, contact_info;
            int user_id = getNextUserId();
            cout << "Enter Workforce details: " << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Contact Information: ";
            cin >> contact_info;
            workforce.push_back(Workforce(name, contact_info, user_id));
            cout << "Your User Id: " << user_id << endl;
        }
        else if (option == 5)
        {
            if (participants.size() == 0 || Events.size() == 0)
            {
                cout << "No participants or events registered" << endl;
                continue;
            }

            int participant_index, event_id;
            cout << "Enter Participant index (0-" << participants.size() - 1 << "): ";
            cin >> participant_index;

            cout << "Choose Event ID: ";
            get_all_events();
            cin >> event_id;

            // Check if the event_id is valid
            if (event_id >= 0 && event_id < Events.size())
            {
                participants[participant_index].registerEvent(event_id);
                cout << "Participant registered for the event." << endl;
            }
            else
            {
                cout << "Invalid Event ID." << endl;
            }
        }
        else if (option == 6)
        {
            if (core_members.size() == 0)
            {
                cout << "No Core members registered." << endl;
                continue;
            }
            if (coordinators.size() == 0)
            {
                cout << "No Coordinators registered." << endl;
                continue;
            }
            int core_member_index, coordinator_index;
            cout << "Enter Core Member index (0-" << core_members.size() - 1 << "): ";
            cin >> core_member_index;
            cout << "Enter Coordinator index (0-" << coordinators.size() - 1 << "): ";
            cin >> coordinator_index;

            core_members[core_member_index].addCoordinator(&coordinators[coordinator_index]);
            cout << "Coordinator added to Core Member." << endl;
        }
        else if (option == 7)
        {
            if (coordinators.size() == 0)
            {
                cout << "No Coordinators registered." << endl;
                continue;
            }
            if (workforce.size() == 0)
            {
                cout << "No Workforce registered." << endl;
                continue;
            }
            int coordinator_index, workforce_index;
            cout << "Enter Coordinator index (0-" << coordinators.size() - 1 << "): ";
            cin >> coordinator_index;
            cout << "Enter Workforce index (0-" << workforce.size() - 1 << "): ";
            cin >> workforce_index;

            coordinators[coordinator_index].addWorkforce(&workforce[workforce_index]);
            cout << "Workforce added to Coordinator." << endl;
        }

        else if (option == 8)
        {
            int user_id;
            cout << "Enter id of user: ";
            cin >> user_id;
            Person *userfromId = getUserFromUserID(user_id);
            displayUserDetails(userfromId);
        }
        else if (option == 9)
        {
            cout << "********************************************\n";
            displayAllCoreMemberDetails();
            cout << "********************************************\n";
        }
        else if (option == 10)
            break;
        else
        {
            cout << "Invalid option. Please choose a valid option." << endl;
        }
    }

    return 0;
}
