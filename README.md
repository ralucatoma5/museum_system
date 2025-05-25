# Museum Management System
## Overview
Museum Management System is a comprehensive C++ console application that simulates a real-world digital museum. It allows both visitors and administrators to interact with a rich set of features, including ticket reservations, VIP loyalty levels, employee scheduling, and exhibition management.

The system emphasizes strong Object-Oriented Programming design, with the use of inheritance, polymorphism, smart pointers, and operator overloading for real-life inspired logic.

## User Roles
### Visitor
Interact with exhibitions, reservations, and loyalty programs.
### Administrator
Manage exhibitions and employees, create work schedules, and oversee operations.

## Key Features
### Visitor Panel
1. View All Exhibitions
Browse all exhibitions with details including visitor capacity, availability, and current average rating.


2. View Ticket Price
Check ticket prices based on the exhibition and visitor's current loyalty level (Standard or VIP).


3. Make a Reservation

    - Reserve tickets for an exhibition.

    - Exhibitions that are full are no longer shown as available.

    - Booking multiple tickets over time accumulates under the same account.

    - Based on the number of tickets purchased, your loyalty level may be upgraded to VIP.

    - Group discounts and first-time discounts are applied automatically.

4. Cancel Reservation

    - Cancel existing reservations.

     - Cancelling frees up tickets and decreases your total ticket count.

    - If excessive cancellations are made, your loyalty level can be downgraded from VIP to Standard.

5. See All Reservations
   - View the list of exhibitions you've reserved, including the number of tickets and exhibition details.

6. See Account Info
- Displays:

    - Your name
    - Number of tickets purchased

    - Current loyalty level (Standard / VIP)

    - Total loyalty points (from quizzes)

7. Take Quiz to Earn Loyalty Points

    - You can take the quiz only once.

    - If you answer at least 5 out of 10 questions correctly, you receive loyalty points.

   - Questions are related to art and the museum world.

8. Rate Exhibitions

    - After visiting, you may rate each exhibition once.

    - Once rated, it disappears from your pending ratings list.

    - Ratings are stored and averaged.

9. See Exhibition Reviews

    - View the average rating for each exhibition.

    - Exhibitions can also be sorted by rating, with alphabetical tiebreakers.

10. See VIP-Only Exhibitions and Perks

- If you're a VIP, you can access:

    - Exclusive exhibitions

    - Free gifts or perks

    - Discounts

- Loyalty upgrades and downgrades depend on your activity:

  - More tickets → Upgrade to VIP

  - Cancellations → Downgrade to Standard


## Admin Panel
1. View All Exhibitions
    - See all exhibitions, their status (full or not), and ticket sales data.
2. Add Exhibition
     - Create new exhibitions with visitor capacity, type, and ticket price.

3. Remove Exhibition
      - Delete an existing exhibition from the system.

4. Schedule Day (Employee Scheduling)

    - Choose a day to assign employees.

    - You can copy the schedule from another existing day.

    - Assign 1 employee per type per day (one cashier, one tour guide, one manager).

    - Once a type is assigned, it is removed from the available options for that day.


5. See Scheduled Days
    - View the employee schedule for each day.

## Loyalty & VIP System
- Loyalty level is calculated based on the total number of tickets purchased.

- VIPs benefit from:

    - Free gifts

    - Exclusive exhibition access

    - Special ticket discounts

- Downgrades to Standard level occur if:

    - Reservations are canceled repeatedly.

    - Ticket purchase count drops below the VIP threshold.

[//]: # (## Cerințe)

[//]: # (- [ ] definirea a minim **2-3 ieararhii de clase** care sa interactioneze in cadrul temei alese &#40;fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic&#41; &#40;6p&#41;)

[//]: # (  - minim o clasa cu:)

[//]: # (    - [ ] constructori de inițializare [*]&#40;https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor&#41;)

[//]: # (    - [ ] constructor supraîncărcat [*]&#40;https://github.com/Ionnier/poo/tree/main/labs/L02#supra%C3%AEnc%C4%83rcarea-func%C8%9Biilor&#41;)

[//]: # (    - [ ] constructori de copiere [*]&#40;https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor&#41;)

[//]: # (    - [ ] `operator=` de copiere [*]&#40;https://github.com/Ionnier/poo/tree/main/labs/L02#supra%C3%AEnc%C4%83rcarea-operatorilor&#41;)

[//]: # (    - [ ] destructor [*]&#40;https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor&#41;)

[//]: # (    - [ ] `operator<<` pentru afișare &#40;std::ostream&#41; [*]&#40;https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L123&#41;)

[//]: # (    - [ ] `operator>>` pentru citire &#40;std::istream&#41; [*]&#40;https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L128&#41;)

[//]: # (    - [ ] alt operator supraîncărcat ca funcție membră [*]&#40;https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L32&#41;)

[//]: # (    - [ ] alt operator supraîncărcat ca funcție non-membră [*]&#40;https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L39&#41; - nu neaparat ca friend)

[//]: # (  - in derivate)

[//]: # (      - [ ] implementarea funcționalităților alese prin [upcast]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding&#41; și [downcast]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast&#41;)

[//]: # (        - aceasta va fi făcută prin **2-3** metode specifice temei alese)

[//]: # (        - funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați )

[//]: # (      - [ ] apelarea constructorului din clasa de bază din [constructori din derivate]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare&#41;)

[//]: # (      - [ ] suprascris [cc]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare&#41;/op= pentru copieri/atribuiri corecte)

[//]: # (      - [ ] destructor [virtual]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding&#41;)

[//]: # (  - pentru celelalte clase se va definii doar ce e nevoie)

[//]: # (  - minim o ierarhie mai dezvoltata &#40;cu 2-3 clase dintr-o clasa de baza&#41;)

[//]: # (  - ierarhie de clasa se considera si daca exista doar o clasa de bază însă care nu moștenește dintr-o clasă din altă ierarhie)

[//]: # (- [ ] cât mai multe `const` [&#40;0.25p&#41;]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere&#41;)

[//]: # (- [ ] funcții și atribute `static` &#40;în clase&#41; [0.5p]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#static&#41;)

[//]: # (  - [ ] 1+ atribute statice non-triviale )

[//]: # (  - [ ] 1+ funcții statice non-triviale)

[//]: # (- [ ] excepții [0.5p]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling&#41;)

[//]: # (  - porniți de la `std::exception`)

[//]: # (  - ilustrați propagarea excepțiilor)

[//]: # (  - ilustrati upcasting-ul în blocurile catch)

[//]: # (  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă)

[//]: # (- [ ] folosirea unei clase abstracte [&#40;0.25p&#41;]&#40;https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte&#41;)

[//]: # ( - [ ] clase template)

[//]: # (   - [ ] crearea unei clase template [&#40;1p&#41;]&#40;https://github.com/Ionnier/poo/tree/main/labs/L08&#41;)

[//]: # (   - [ ] 2 instanțieri ale acestei clase &#40;0.5p&#41;)

[//]: # ( - STL [&#40;0.25p&#41;]&#40;https://github.com/Ionnier/poo/tree/main/labs/L07#stl&#41;)

[//]: # (   - [ ] utilizarea a două structuri &#40;containere&#41; diferite &#40;vector, list sau orice alt container care e mai mult sau mai putin un array&#41;)

[//]: # (   - [ ] utilizarea a unui algoritm cu funcție lambda &#40;de exemplu, sort, transform&#41;)

[//]: # ( - Design Patterns [&#40;0.75p&#41;]&#40;https://github.com/Ionnier/poo/tree/main/labs/L08&#41;)

[//]: # (   - [ ] utilizarea a două șabloane de proiectare)

