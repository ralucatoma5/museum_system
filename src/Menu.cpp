#include "../include/Menu.h"
#include "../include/Utils.h"
#include "../include/Exhibition.h"
#include "../include/ExhibitionFactory.h"
#include "../include/Question.h"
#include "../include/Quiz.h"
#include "../include/Manager.h"
#include "../include/TourGuide.h"
#include "../include/Cashier.h"
#include "../include/StandardVisitor.h"
#include "../include/VipVisitor.h"
Menu::Menu() {}

Menu& Menu::getMenu() {
    static Menu menu;
    return menu;
}


void Menu::seedData(
        std::vector<std::shared_ptr<Exhibition>>& exhibitions,
        std::vector<std::shared_ptr<Visitor>>& visitors,
        std::vector<std::shared_ptr<Employees>>& employees,
        std::vector<std::shared_ptr<Ticket<VipVisitor, VipExhibitionEvent>>>& vipTickets) {

    std::shared_ptr<StandardVisitor> standardVisitor = std::make_shared<StandardVisitor>("user", "parola", 10, true, "Senior");
    std::shared_ptr<VipVisitor> vipVisitor = std::make_shared<VipVisitor>("raluca", "pass", 220, true, "Student", "Gold");
    visitors.push_back(standardVisitor);
    visitors.push_back(vipVisitor);

    visitors.push_back(std::make_shared<StandardVisitor>("alex_popescu", "alex", 0, true, "Student"));
    visitors.push_back(std::make_shared<StandardVisitor>("elena", "elena123", 35, false, "Senior"));
    visitors.push_back(std::make_shared<VipVisitor>("cristina_neagu", "neagu321", 150, false, "Adult", "Silver"));

    std::map<std::string, std::string> fashionPerks = {
        {"Silver", "Priority Seating"},
        {"Gold", "Designer Meet & Greet"},
        {"Diamond", "Backstage Access"}
    };

    std::map<std::string, std::string> fashionGifts = {
        {"Silver", "Fashion Week Tote Bag"},
        {"Gold", "Designer Scarf"},
        {"Diamond", "Luxury Gift Box"}
    };

    std::map<std::string, std::string> perks = {
        {"Silver", "Priority Entry"},
        {"Gold", "VIP Lounge Access"},
        {"Diamond", "Backstage Tour"}
    };

    std::map<std::string, std::string> gifts = {
        {"Silver", "Free Drink"},
        {"Gold", "VIP T-Shirt"},
        {"Diamond", "Exclusive Merch"}
    };

    std::shared_ptr<ArtExhibition> artExhibition = std::make_shared<ArtExhibition>("Modern Art", 30, "Picasso", "Cubism");
    exhibitions.push_back(artExhibition);
    exhibitions.push_back(std::make_shared<ArtExhibition>("Impressionist Masterpieces", 50, "Claude Monet", "Impressionism"));
    exhibitions.push_back(std::make_shared<ArtExhibition>("Surrealist Dreams", 40, "Salvador Dalí", "Surrealism"));
    exhibitions.push_back(std::make_shared<ArtExhibition>("Classical Portraits", 35, "Leonardo da Vinci", "Renaissance"));

    std::shared_ptr<ScienceExhibition> scienceExhibition = std::make_shared<ScienceExhibition>("Tech World", 20, "Physics", true);
    exhibitions.push_back(scienceExhibition);
    exhibitions.push_back(std::make_shared<ScienceExhibition>("Physics Wonders", 100, "Physics", true));
    exhibitions.push_back(std::make_shared<ScienceExhibition>("Space Exploration", 120, "Astronomy", true));
    exhibitions.push_back(std::make_shared<ScienceExhibition>("Sustainable Energy", 75, "Environmental Science", false));

    exhibitions.push_back(std::make_shared<HistoryExhibition>("Ancient Egypt", 70, "Pharaohs Era", 150));
    exhibitions.push_back(std::make_shared<HistoryExhibition>("World War II Memorabilia", 50, "20th Century", 100));
    exhibitions.push_back(std::make_shared<HistoryExhibition>("Viking Artifacts", 60, "Medieval Europe", 80));
    exhibitions.push_back(std::make_shared<HistoryExhibition>("Roman Empire", 85, "1st Century", 120));


    std::shared_ptr<VipExhibitionEvent> vipExhibitionArt = std::make_shared<VipExhibitionEvent>("Luxury Art Showcase", 50, "19:00", "Grand Hall", perks, gifts);
    exhibitions.push_back(vipExhibitionArt);
    std::shared_ptr<VipExhibitionEvent> vipExhibitionFashion = std::make_shared<VipExhibitionEvent>("Fashion Week Gala", 120, "20:00", "Royal Ballroom", fashionPerks, fashionGifts);
    exhibitions.push_back(vipExhibitionFashion);
    std::map<std::string, std::string> musicPerks = {
        {"Silver", "Backstage pass"},
        {"Gold", "Meet the band"},
        {"Diamond", "Private soundcheck access"}
    };

    std::map<std::string, std::string> musicGifts = {
        {"Silver", "Signed poster"},
        {"Gold", "Limited edition vinyl"},
        {"Diamond", "Personalized guitar pick"}
    };

    auto vipExhibitionMusic = std::make_shared<VipExhibitionEvent>(
        "Jazz Night Live", 90, "21:00", "Concert Hall", musicPerks, musicGifts);
    exhibitions.push_back(vipExhibitionMusic);

    employees.push_back(std::make_shared<Manager>("Elena Dumitrescu", 45, 8200, "Marketing"));
    employees.push_back(std::make_shared<Manager>("Ana Georgescu", 43, 8300, "IT"));
    employees.push_back(std::make_shared<Manager>("Cristian Marin", 38, 7500, "Sales"));
    employees.push_back(std::make_shared<TourGuide>("Andreea Stoica", 27, 3700, std::vector<std::string>{"romanian", "english", "french"}));
    employees.push_back(std::make_shared<TourGuide>("Vlad Radu", 30, 3900, std::vector<std::string>{"romanian", "italian"}));
    employees.push_back(std::make_shared<TourGuide>("Maria Dobre", 26, 3500, std::vector<std::string>{"romanian", "english"}));
    employees.push_back(std::make_shared<Cashier>("Radu Popa", 23, 3200, 301));
    employees.push_back(std::make_shared<Cashier>("Sorina Iancu", 28, 3400, 302));
    employees.push_back(std::make_shared<Cashier>("Marius Tudor", 24, 3100, 303));
    employees.push_back(std::make_shared<Cashier>("Anca Neagu", 26, 3300, 304));
    employees.push_back(std::make_shared<Cashier>("Alexandru Voicu", 30, 3500, 305));

    vipTickets.push_back(std::make_shared<Ticket<VipVisitor, VipExhibitionEvent>>(vipVisitor, vipExhibitionFashion, 1));
    vipTickets.push_back(std::make_shared<Ticket<VipVisitor, VipExhibitionEvent>>(vipVisitor, vipExhibitionMusic, 1));
    vipTickets.push_back(std::make_shared<Ticket<VipVisitor, VipExhibitionEvent>>(vipVisitor, vipExhibitionArt, 1));

}
void Menu::showAdminMenu() {
    std::cout << "\n--- Exhibition Management Menu ---\n";
    std::cout << "1. View All Exhibitions\n";
    std::cout << "2. Add Exhibition\n";
    std::cout << "3. Remove Exhibition\n";
    std::cout << "4. Schedule day\n";
    std::cout << "5. See scheduled days\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter choice: ";
}

void Menu::showVisitorMenu() {
    std::cout << "\n--- Visitor Menu ---\n";
    std::cout << "1. View All Exhibitions\n";
    std::cout << "2. View Ticket Price\n";
    std::cout << "3. Make a Reservation\n";
    std::cout << "4. Cancel Reservation\n";
    std::cout << "5. See All Reservations\n";
    std::cout << "6. See account info\n";
    std::cout << "7. Take Quiz to earn loyalty points\n";
    std::cout << "8. Rate the exhibits you had tickets to\n";
    std::cout << "9. See exhibitions reviews\n";
    std::cout << "10. See the tickets you can buy with Vip Level\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter choice: ";
}

void  Menu::handleAdminChoice(int choice, std::vector<std::shared_ptr<Exhibition>>& exhibitions, const std::vector<std::shared_ptr<Employees>>& employees, std::map<std::string, std::vector<std::shared_ptr<Employees>>>& schedule){
        switch (choice) {
            case 1: {
                std::cout << "--- Exhibitions ---\n";
                for (size_t i = 0; i < exhibitions.size(); i++) {
                    std::cout << i+1 << ". " << *exhibitions[i] << "\n";
                }
                break;
            }
            case 2: {
                std::string section;
                std::cout << "Exhibition section (Art/ History/ Science/ Vip): ";
                std::cin >> section;
                section = capitalizeWord(section);
                std::shared_ptr<ExhibitionFactory> factory = nullptr;
                if (section == "Art") {
                    factory = std::make_shared<ArtExhibitionFactory>();
                } else if (section == "Science") {
                    factory = std::make_shared<ScienceExhibitionFactory>();
                } else if (section == "History") {
                    factory = std::make_shared<HistoryExhibitionFactory>();
                } else if (section == "Vip") {
                    factory = std::make_shared<VipExhibitionFactory>();
                } else {
                    std::cout << "Please enter a valid section\n";
                }

                if (factory) {
                    auto exhibition = factory -> createExhibition();
                    exhibitions.push_back(exhibition);
                    std::cout << "Exhibition added successfully!\n";
                }
                break;
            }
            case 3: {
                std::cout << "--- Exhibitions ---\n";
                for (size_t i = 0; i < exhibitions.size(); i++) {
                    std::cout << i+1 << ". " << *exhibitions[i] << "\n";
                }
                int exhNr;
                std::cout << "Enter the index of the exhibition you want to delete: ";
                std::cin >> exhNr;
                deleteExhibitionByIndex(exhibitions, exhNr);
                break;
            }
            case 4: {
                std::string day;
                std::cout << "Enter day to schedule: ";
                std::cin >> day;

                if (!schedule.empty()) {
                    std::cout << "Copy schedule from another day? (yes/no): ";
                    std::string response;
                    std::cin >> response;
                    if (response == "yes") {
                        std::cout << "Scheduled days:\n";
                        for (const auto& s : schedule)
                            std::cout << "- " << s.first << "\n";
                        std::string copyDay;
                        std::cout << "Enter day to copy from: ";
                        std::cin >> copyDay;
                        if (schedule.find(copyDay) != schedule.end()) {
                            std::vector<std::shared_ptr<Employees>> clonedSchedule;

                            for (const auto& emp : schedule[copyDay]) {
                                clonedSchedule.push_back(emp->clone());
                            }

                            schedule[day] = clonedSchedule;
                            std::cout << "Copied schedule from " << copyDay << " to " << day << "\n";
                        }
                        else {
                            std::cout << "No such day scheduled.\n";
                        }
                    } else {
                        scheduleAllEmployees(employees, schedule, day);
                    }
                } else {
                        scheduleAllEmployees(employees, schedule, day);
                }

                break;
            }
            case 5: {
                if (schedule.empty())
                    std::cout << "There are no scheduled days\n";
                else {
                    std::cout << "Scheduled days:\n";
                    printSchedule(schedule);
                }
                break;
            }
            case 0:
                std::cout << "Goodbye!\n";
                break;

            default:
                std::cout << "Invalid option. Try again.\n";
        }
    }

    void Menu::handleVisitorChoice(int choice, std::vector<std::shared_ptr<Exhibition>>& exhibitions,  std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& ratedTickets, bool& gamePlayed, std::shared_ptr<Visitor>& currentVisitor, std::vector<std::shared_ptr<Visitor>>& visitors, std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>>& tickets, std::vector<std::shared_ptr<Ticket<VipVisitor, VipExhibitionEvent>>> vipTickets){


        switch (choice) {
            case 1: {
                std::cout << "--- Exhibitions ---\n";
                auto vipVisitor = std::dynamic_pointer_cast<VipVisitor>(currentVisitor);
                for (size_t i = 0; i < exhibitions.size(); i++) {
                    auto vipExhibition = std::dynamic_pointer_cast<VipExhibitionEvent>(exhibitions[i]);
                    if (!vipExhibition)
                        std::cout << i+1 << ". " << *exhibitions[i] << "\n";
                    else if(vipExhibition && vipVisitor) {
                        std::cout << i+1 << ". ";
                        vipExhibition ->printForYou(std::cout, vipVisitor -> getVipLevel());
                    }
                }
                break;
            }
            case 2: {
                std::cout << "--- Ticket Prices ---\n";
                for (size_t i = 0; i < exhibitions.size(); i++) {
                    double price = exhibitions[i]->getTicketPrice() * (1 - currentVisitor->getDiscount(false));
                    std::cout << i+1 << ". " << exhibitions[i]->getName() << " " << exhibitions[i]->getTicketPrice()
                          << " lei (Your price: " << price << " lei)\n";
                }
                break;
            }
            case 3: {
                std::cout << "--- Available Exhibitions ---n";
                auto vipVisitor = std::dynamic_pointer_cast<VipVisitor>(currentVisitor);
                std::vector<std::shared_ptr<Exhibition>> freeExhibitions;
                for (size_t i = 0; i < exhibitions.size(); i++) {
                    if (!exhibitions[i]->isFull()) {
                        freeExhibitions.push_back(exhibitions[i]);
                    }
                }
                int exhNr = 0;
                for (size_t i = 0; i < freeExhibitions.size(); i++) {
                    auto vipExhibition = std::dynamic_pointer_cast<VipExhibitionEvent>(freeExhibitions[i]);
                    if (!vipExhibition) {
                        std::cout << i+1 << ". " << *freeExhibitions[i] << "\n";
                        exhNr++;
                    }
                    else if(vipExhibition && vipVisitor) {
                        std::cout << i+1 << ". ";
                        vipExhibition ->printForYou(std::cout, vipVisitor -> getVipLevel());
                        exhNr++;
                    }
                }

                int exhChoice;


                std::string response;
                std::cout << "Select exhibition (enter number): ";
                std::cin >> exhChoice;
                if (exhChoice > exhNr || exhChoice < 0) {
                    std::cout << "Invalid exhibition choice";
                    break;
                }
                double price = freeExhibitions[exhChoice-1]->getTicketPrice() * (1 - currentVisitor->getDiscount(false));
                std::cout<< "The price for one ticket for this exhibitions will be: " << price <<"\n";
                std::cout << "Do you want to make a reservation? (yes/no): ";
                std::cin >> response;
                if (response == "yes") {
                    if (exhChoice > 0 && exhChoice < static_cast<int>(freeExhibitions.size())) {
                        auto selectedExhibition = freeExhibitions[exhChoice - 1];
                        if (!selectedExhibition->isFull()) {
                            int nrTickets;
                            std::cout << "How many tickets do you want: ";
                            std::cin >> nrTickets;
                            bool firstTime = currentVisitor -> getIsFirstTimeVisitor();
                            if (nrTickets + selectedExhibition-> getCurrentVisitors() <= selectedExhibition->getMaxVisitors()) {
                                if (firstTime) {
                                    std::cout << "You are a first time visitor, a discount of 10% will be added\n";
                                }
                                if (nrTickets >= 7) {
                                    std::cout << "You have group discount! \n";
                                }
                                selectedExhibition->incrementVisitors(nrTickets);
                                handleReservation(tickets, currentVisitor, selectedExhibition, nrTickets, visitors);
                            }
                            else {
                                int ticketsAvailable = selectedExhibition->getMaxVisitors() - selectedExhibition-> getCurrentVisitors();
                                std::cout << "There are only "<< ticketsAvailable << " tickets available\n";
                            }

                        } else {
                            std::cout << "This exhibition is full!\n";
                        }
                    } else {
                        std::cout << "Invalid exhibition choice.\n";
                    }
                }
                break;
            }
            case 4: {
                if (!tickets.empty()) {
                    int reservationIndex;

                    for (size_t i = 0; i < tickets.size(); i++) {
                        std::cout << i + 1 << ". " << *tickets[i];
                    }
                    std::cout << "Pick the number of the reservation that you want to cancel: ";
                    std::cin >> reservationIndex;
                    if (reservationIndex > static_cast<int>(tickets.size())) {
                        std::cout << "Invalid index";
                        break;
                    }
                    auto selectedExhibition = tickets[reservationIndex-1]->getExhibition();
                    std::cout <<"\n" <<*selectedExhibition <<"\n";
                    selectedExhibition->decrementVisitors(tickets[reservationIndex-1]->getNrTickets());
                    handleCanceledReservation(tickets, currentVisitor, reservationIndex, visitors);
                }
                else
                    std::cout << "There are no reservations made \n";
                break;
            }
            case 5: {
                if (!tickets.empty())
                    for (const auto& ticket: tickets)
                        std::cout << *ticket << "\n";
                else
                    std::cout << "There are no reservations made \n";

                break;
            }

            case 6: {
                std::cout<<*currentVisitor;
                std::cout<<"You bought " << Exhibition::getAllTicketsSold() << " tickets \n";
                std::cout<<"You have spent " << Ticket<Visitor, Exhibition>::getMoneySpent() << " lei"<<"\n";
                break;
            }

            case 7: {
                if (!gamePlayed) {
                    std::vector<Question> questions = {
                        Question("What art movement is Picasso associated with?", {"Cubism", "Impressionism", "Surrealism", "Baroque"}, 0),
                        Question("Who painted the Mona Lisa?", {"Van Gogh", "Picasso", "Leonardo da Vinci", "Michelangelo"}, 2),
                        Question("Which artist is famous for 'The Starry Night'?", {"Van Gogh", "Monet", "Dali", "Rembrandt"}, 0),
                        Question("What ancient civilization built the pyramids of Giza?", {"Egyptians", "Romans", "Greeks", "Aztecs"}, 0),
                        Question("Who is known as the father of modern physics?", {"Einstein", "Newton", "Galileo", "Bohr"}, 0),
                        Question("Which Renaissance artist painted the Sistine Chapel ceiling?", {"Michelangelo", "Leonardo da Vinci", "Raphael", "Donatello"}, 0),
                        Question("What is the largest planet in our solar system?", {"Jupiter", "Saturn", "Earth", "Mars"}, 0),
                        Question("Who was the first human to travel into space?", {"Yuri Gagarin", "Neil Armstrong", "Buzz Aldrin", "Alan Shepard"}, 0)
                    };

                    Quiz quiz(questions);
                    if (quiz.startQuiz()) {
                        gamePlayed = true;
                        if (quiz.winQuiz())
                            currentVisitor->addLoyaltyPoints(50);
                    }
                } else {
                    std::cout << "You have already took this quiz!";
                }
                break;
            }

            case 8: {

                std::vector<std::shared_ptr<Ticket<Visitor, Exhibition>>> toRateTickets;
                toRateTickets.clear();
                for (const auto& ticket : tickets) {
                    bool alreadyRated = false;
                    for (const auto& rated : ratedTickets) {
                        if (*ticket == *rated) {
                            alreadyRated = true;
                            break;
                        }
                    }
                    if (!alreadyRated) {
                        toRateTickets.push_back(ticket);
                    }
                }

                for (size_t i = 0; i < toRateTickets.size(); i++) {
                    std::string exhibitionName = (toRateTickets[i]->getExhibition()) -> getName();
                    std::cout << i+1 << ". " << exhibitionName << "\n";
                }

                if (!toRateTickets.empty()) {
                    int index;
                    double rating;
                    std::cout << "Choose the index of the exhibition that you want to rate: ";
                    std::cin >> index;
                    index--;
                    if (index >= 0 && index < static_cast<int>(toRateTickets.size())) {
                        std::cout << "Rate it from 1 to 5: ";
                        std::cin >> rating;
                        (toRateTickets[index] ->getExhibition()) -> addRating(rating);
                        ratedTickets.push_back(toRateTickets[index]);
                    } else {
                        std::cout << "Choose a valid index \n";
                    }
                }
                break;
            }

            case 9: {
                Exhibition::sortExhibitionsByRating(exhibitions);
                for (const auto& exhibition : exhibitions) {
                    std::cout << exhibition -> getName() << " " << exhibition -> getAverageRating() << "\n";
                }
                break;
            }

            case 10: {
                std::cout << "You need " << 100 - currentVisitor->getLoyaltyPoints() << " more points to become VIP";
                std::cout << "\n";
                for (size_t i = 0; i < vipTickets.size(); i++) {
                    std::cout << *vipTickets[i] << "\n\n";
                }
                break;
            }

            case 0: {
                std::cout << "Goodbye!\n";
                break;
            }

            default:
                std::cout << "Invalid option. Try again.\n";
        }

    }
