#include "../include/Ticket.h"

template <>
double Ticket<Visitor, Exhibition>::moneySpent = 0;


template <>
double Ticket<VipVisitor, VipExhibitionEvent>::moneySpent = 0;


template class Ticket<Visitor, Exhibition>;
template class Ticket<VipVisitor, VipExhibitionEvent>;