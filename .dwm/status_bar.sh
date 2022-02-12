#!/bin/sh

kill_existing() {
    instance_pid="$(pgrep -fo "/bin/sh /home/flyingsl0ths/.dwm/status_bar.sh")"

    if [ "$instance_pid" != "$$" ]; then
        kill -KILL "$instance_pid"
    fi
}

status_bar() {
    wifi_connection="[^c#ABE9B3^  ^c#D9E0EE^$(nmcli -t -f name connection show --active | awk '{print $1}')]"

    ram_usage="[^c#F8BD96^ ^c#D9E0EE^$(free -h --si | grep Mem | awk '{print ($3)}')]"

    todays_date="[^c#E8A2AF^  ^c#D9E0EE^$(date +"%b %d, %Y %a %I:%M%p")]"

    battery_level="[^c#B5E8E0^  ^c#D9E0EE^$(cat /sys/class/power_supply/BAT1/capacity)%]"

    volume_level="[^c#C9CBFF^ ^c#D9E0EE^$(pamixer --get-volume-human)]"

    xsetroot -name "$wifi_connection $ram_usage $todays_date $battery_level $volume_level"
}

kill_existing

while true; do
    status_bar
    sleep 0.5s
done
