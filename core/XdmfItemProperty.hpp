/*****************************************************************************/
/*                                    XDMF                                   */
/*                       eXtensible Data Model and Format                    */
/*                                                                           */
/*  Id : XdmfItemProperty.hpp                                                */
/*                                                                           */
/*  Author:                                                                  */
/*     Kenneth Leiter                                                        */
/*     kenneth.leiter@arl.army.mil                                           */
/*     US Army Research Laboratory                                           */
/*     Aberdeen Proving Ground, MD                                           */
/*                                                                           */
/*     Copyright @ 2011 US Army Research Laboratory                          */
/*     All Rights Reserved                                                   */
/*     See Copyright.txt for details                                         */
/*                                                                           */
/*     This software is distributed WITHOUT ANY WARRANTY; without            */
/*     even the implied warranty of MERCHANTABILITY or FITNESS               */
/*     FOR A PARTICULAR PURPOSE.  See the above copyright notice             */
/*     for more information.                                                 */
/*                                                                           */
/*****************************************************************************/

#ifndef XDMFITEMPROPERTY_HPP_
#define XDMFITEMPROPERTY_HPP_

// Includes
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>
#include "XdmfCore.hpp"

/**
 * @brief Represents a property attached to an XdmfItem.
 *
 * XdmfItems can have zero or more properties attached to them that describe a specific characteristic of that item.
 * For instance, XdmfAttributes have both Type and Center Properties.
 *
 * This is an abstract base class to facilitate reading and writing of properties in a generic way.
 */

class XDMFCORE_EXPORT XdmfItemProperty {

public:

	virtual ~XdmfItemProperty() = 0;

	/**
	 * Retrieve the key/value pairs that this XdmfItemProperty contains by inserting into the passed vector.
	 *
	 * @param collectedProperties a std::vector<std::pair<std::string, std::string> > to insert name / value pairs into.
	 */
	virtual void getProperties(std::map<std::string, std::string> & collectedProperties) const = 0;

protected:

	XdmfItemProperty();

private:

	XdmfItemProperty(const XdmfItemProperty&);  // Not implemented.
	void operator=(const XdmfItemProperty&);  // Not implemented.

};

#endif /* XDMFITEMPROPERTY_HPP_ */
