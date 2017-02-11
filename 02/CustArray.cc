/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

#include "CustArray.h"

CustArray::CustArray()
{
  size = 0;
}

int CustArray::getSize() { return size; }

Customer* CustArray::get(int index)
{
  if (index < 0 || index >= size)
  {
    std::cout << "Error: Customer not found" << std::endl;
    exit(1);
  }
  return elements[index];
}

void CustArray::add(Customer* cust)
{
  if (size >= MAX_ARR)
    return;

  elements[size++] = cust;
}

