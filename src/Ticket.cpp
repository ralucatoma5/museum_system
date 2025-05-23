#include "../include/Ticket.h"

template <>
double Ticket<Visitor, Exhibition>::moneySpent = 0;


template <>
double Ticket<VipVisitor, VipExhibitionEvent>::moneySpent = 0;
