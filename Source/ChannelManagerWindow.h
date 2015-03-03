//--------------------------------------------------------------------------------------------------
//
//  File:       ChannelManagerWindow.h
//
//  Project:    M+M
//
//  Contains:   The class declaration for the primary window of the channel manager application.
//
//  Written by: Norman Jaffe
//
//  Copyright:  (c) 2014 by H Plus Technologies Ltd. and Simon Fraser University.
//
//              All rights reserved. Redistribution and use in source and binary forms, with or
//              without modification, are permitted provided that the following conditions are met:
//                * Redistributions of source code must retain the above copyright notice, this list
//                  of conditions and the following disclaimer.
//                * Redistributions in binary form must reproduce the above copyright notice, this
//                  list of conditions and the following disclaimer in the documentation and/or
//                  other materials provided with the distribution.
//                * Neither the name of the copyright holders nor the names of its contributors may
//                  be used to endorse or promote products derived from this software without
//                  specific prior written permission.
//
//              THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//              EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//              OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//              SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//              INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//              TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//              BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//              CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//              ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//              DAMAGE.
//
//  Created:    2014-07-14
//
//--------------------------------------------------------------------------------------------------

#if (! defined(ChannelManagerWindow_H_))
# define ChannelManagerWindow_H_ /* Header guard */

# include "ChannelManagerDataTypes.h"

# if defined(__APPLE__)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunknown-pragmas"
#  pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# endif // defined(__APPLE__)
/*! @file
 
 @brief The class declaration for the primary window of the channel manager application. */
# if defined(__APPLE__)
#  pragma clang diagnostic pop
# endif // defined(__APPLE__)

namespace ChannelManager
{
    class ContentPanel;
    class EntitiesPanel;
    class ScannerThread;
    
    /*! @brief The main window of the application. */
    class ChannelManagerWindow : public DocumentWindow,
                                 private AsyncUpdater
    {
    public :
        
        /*! @brief The commands that we respond to.
         
         Note that this must use the 'old-style' @c enum form, as it's referenced in code that
         uses 'old-style' values. */
        enum CommandIDs
        {
            /*! @brief The command to trigger a repaint. */
            kCommandDoRepaint = 0x2000,
            
            /*! @brief The command to invert the background gradient. */
            kCommandInvertBackground = 0x2001,
            
            /*! @brief The command to set the background to white. */
            kCommandWhiteBackground = 0x2002
            
        }; // CommandIDs

        /*! @brief The constructor.
         @param title The window title. */
        ChannelManagerWindow(const yarp::os::ConstString & title);
        
        /*! @brief The destructor. */
        virtual ~ChannelManagerWindow(void);
        
        /*! @brief This method is called when the user tries to close the window. */
        void closeButtonPressed(void);
        
        /*! @brief Returns the command manager object used to dispatch command events.
         @returns The command manager object used to dispatch command events. */
        static ApplicationCommandManager & getApplicationCommandManager(void);
        
        /*! @brief Returns the entities panel.
         @returns The entities panel. */
        EntitiesPanel & getEntitiesPanel(void)
        const;
        
        /*! @brief Return the reference to the background scanning thread.
         @returns The reference to the background scanning thread. */
        inline ScannerThread * getScannerThread(void)
        const
        {
            return _scannerThread;
        } // getScannerThread
        
        /*! @brief Called back to perform operations. */
        virtual void handleAsyncUpdate(void);

        /*! @brief Set up the reference to the background scanning thread. */
        void setScannerThread(ScannerThread * theScanner);
        
    protected :
        
    private :
        
    public :
    
    protected :
    
    private :
        
        /*! @brief The first class that this class is derived from. */
        typedef DocumentWindow inherited1;
        
        /*! @brief The second class that this class is derived from. */
        typedef AsyncUpdater inherited2;
        
        /*! @brief The connections panel. */
        ScopedPointer<Component> _connectionsPanel;
        
        /*! @brief The content area of the window. */
        ScopedPointer<ContentPanel> _contentPanel;
        
        /*! @brief A reference to the background scanning thread. */
        ScannerThread * _scannerThread;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChannelManagerWindow)
        
    }; // ChannelManagerWindow
    
} // ChannelManager

#endif // ! defined(ChannelManagerWindow_H_)
