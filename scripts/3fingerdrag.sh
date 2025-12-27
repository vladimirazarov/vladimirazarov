#!/bin/bash
# Wait for the desktop to load
sleep 5
# Export the socket so ydotool knows where to go
export YDOTOOL_SOCKET="/tmp/.ydotool_socket"
# Start fusuma in the background
/usr/local/bin/fusuma -d > /tmp/fusuma.log 2>&1
