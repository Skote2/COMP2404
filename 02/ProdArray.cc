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

#include "ProdArray.h"

ProdArray::ProdArray()
{
  size = 0;
}

int ProdArray::getSize() { return size; }

Product& ProdArray::get(int index)
{
  if (index < 0 || index >= size)
  {
    std::cout << "Out of bounds index" << std::endl;
    exit(1);
  }
  return elements[index];
}

void ProdArray::add(Product& prod)
{
  if (size >= MAX_ARR)
    return;

  elements[size++] = prod;
}

Product& ProdArray::findProd (int prodId)
{
   for (int i = 0; i < size; i++)
    if (elements[i].getId() == prodId)
      return elements[i];
      //Ids star at 5065
  std::cout << "Product ID not found" << std::endl;
  exit(1);
}