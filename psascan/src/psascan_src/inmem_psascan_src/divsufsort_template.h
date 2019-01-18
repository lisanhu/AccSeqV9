/**
 * @file    src/psascan_src/inmem_psascan_src/divsufsort_template.h
 * @author  Dominik Kempa <dominik.kempa (at) gmail.com>
 *
 * @section LICENCE
 *
 * This file is part of pSAscan v0.1.0
 * See: http://www.cs.helsinki.fi/group/pads/
 *
 * Copyright (C) 2014-2015
 *   Juha Karkkainen <juha.karkkainen (at) cs.helsinki.fi>
 *   Dominik Kempa <dominik.kempa (at) gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 **/

#ifndef __PSASCAN_SRC_INMEM_PSASCAN_SRC_DIVSUFSORT_TEMPLATE_H_INCLUDED
#define __PSASCAN_SRC_INMEM_PSASCAN_SRC_DIVSUFSORT_TEMPLATE_H_INCLUDED

#include <cstdio>
#include <cstdlib>

#include "divsufsort.h"
#include "divsufsort64.h"


namespace psascan_private {
namespace inmem_psascan_private {

template<typename T>
void run_divsufsort(const unsigned char *, T*, T) {
  fprintf(stderr, "\ndivsufsort: non-standard call. Use either"
      "int or long for second and third argument.\n");
  std::exit(EXIT_FAILURE);
}

template<>
void run_divsufsort(const unsigned char *text, int *sa, int length) {
  divsufsort(text, sa, length);
}

//template
void run_divsufsort(const unsigned char *text, long *sa, long length) {
  divsufsort64(text, sa, length);
}

}  // namespace inmem_psascan_private
}  // namespace psascan_private

#endif  // __PSASCAN_SRC_INMEM_PSASCAN_SRC_DIVSUFSORT_TEMPLATE_H_INCLUDED
