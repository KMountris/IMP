/*
 * IMP. Image and Mesh Processing library.
 * Copyright (C) 2016  <Konstantinos A. Mountris> <konstantinos.mountris@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


/**
   \file inr_io.hpp
   \brief InrIO class header file.
   \author Konstantinos A. Mountris
   \date 31/10/2017
*/

#ifndef IMP_ENGINE_IMAGE_IO_INR_IO_HPP_
#define IMP_ENGINE_IMAGE_IO_INR_IO_HPP_

#include "IMP/engine/image/voxel_image.hpp"
#include "IMP/engine/utilities/timer.hpp"

#include <string>
#include <stdexcept>
#include <exception>

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstddef>

#include <algorithm>

#include <boost/filesystem.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filter/counter.hpp>
#include <boost/iostreams/copy.hpp>

namespace IMP {

/** \addtogroup ImageIO \{ */


/**
 * \class InrIO
 * \brief Class implemmenting input/output for voxelized images in Inria format [.inr].
 */


class InrIO{
public:

      /**
       * \brief InrIO constructor.
       */
      inline InrIO();


      /**
       * \brief InrIO destructor.
       */
      inline virtual ~InrIO();


      /**
       * \brief Load voxelized image.
       *
       * The voxelized image format must be in Inria format (.inr).
       *
       * \param[in] filename The filename (with full path) of the image to load.
       * \param[out] image The voxelized image where image data will be loaded.
       * \return [void]
       *
       */
      template <typename VOXELTYPE>
      inline void Load(const std::string &filename, VoxelImage<VOXELTYPE> &image);


      /**
       * \brief Save voxelized image to Inria file format (.mhd).
       * \param[in] image The voxelized image to be saved.
       * \param[in] filename The filename (with full path) to save the image.
       * \param[in] compression The desired compression state (ON/OFF) for the output image.
       * \return [void]
       *
       */
      template <typename VOXELTYPE>
      inline void Save(VoxelImage<VOXELTYPE> &image, const std::string &filename, const ImageCompression &compression);



private:

      /**
       * \brief Extract an attribute from a Inria image header (.inr).
       * \param[in] line The line of the Inria image header (.inr) to be processed.
       * \param[out] attribute The attribute that will be extracted.
       * \return [void]
       */
      template<typename DATATYPE>
      inline void ExtractAttributeFromHeader(const std::string &line, DATATYPE &attribute);


};


/** @} End of Doxygen Groups*/
} //end of namespace IMP

#endif //IMP_ENGINE_IMAGE_IO_INR_IO_HPP_

#include "IMP/engine/image_io/inr_io.tpp"
